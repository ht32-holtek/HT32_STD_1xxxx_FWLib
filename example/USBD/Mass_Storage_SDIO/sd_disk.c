/*********************************************************************************************************//**
 * @file    USBD/Mass_Storage_SDIO/sd_disk.c
 * @version $Rev:: 3533         $
 * @date    $Date:: 2025-07-25 #$
 * @brief   The SD Disk related function.
 *************************************************************************************************************
 * @attention
 *
 * Firmware Disclaimer Information
 *
 * 1. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
 *    proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
 *    other intellectual property laws.
 *
 * 2. The customer hereby acknowledges and agrees that the program technical documentation, including the
 *    code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
 *    other than HOLTEK and the customer.
 *
 * 3. The program technical documentation, including the code, is provided "as is" and for customer reference
 *    only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
 *    the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
 *    the warranties of merchantability, satisfactory quality and fitness for a particular purpose.
 *
 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 ************************************************************************************************************/

/* Includes ------------------------------------------------------------------------------------------------*/
#include "sd_disk.h"
#include "sdio_sd.h"
#include "ht32_board_config.h"

/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup USBD_Examples USBD
  * @{
  */

/** @addtogroup Mass_Storage_SDIO
  * @{
  */


#if (BOT_SD_DISK0 == 1)
/* Settings ------------------------------------------------------------------------------------------------*/
#define SDISK_READ_BUFFER      HTCFG_SDISK_READ_BUFFER
//#define SDDISK_DEBUG
#if defined(SDDISK_DEBUG)
#define _SDDISK_DEBUG_PRINTF  printf
#else
#define _SDDISK_DEBUG_PRINTF(...)
#endif
/* Private types -------------------------------------------------------------------------------------------*/
typedef enum
{
  SDDISK_IDLE  = 0,
  SDDISK_READ  = 1,
  SDDISK_WRITE = 2,
} SDDISK_Status_Enum;

/* Private constants ---------------------------------------------------------------------------------------*/
#define CACHE_CNT  (SDISK_READ_BUFFER / SDDISK0_BlockSize)

/* Private macro -------------------------------------------------------------------------------------------*/
#if (SDISK_DEBUG == 1)
#define DBG   printf
#else
#define DBG(...)
#endif

/* Private variables ---------------------------------------------------------------------------------------*/
__ALIGN4 static u8 guReadBuffer[SDISK_READ_BUFFER];
__ALIGN4 static u8 guWriteBuffer[SDDISK0_BlockSize];
static u32 guReadBufferOffset;
static u32 guWriteBufferOffset;
static SDDISK_Status_Enum gDiskWriteStatus = SDDISK_IDLE;

static u32 uCachePage = 0xFFFFFFFF;
static u32 uCurrentBlock = 0xFFFFFFFF;

u32 bSDDiskUnload = FALSE;
SD_CardInfo SDCardInfo;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Read from SD Disk memory.
  * @param  uId: SD Disk ID
  * @param  pBuffer: Pointer of data buffer
  * @param  uBlockAddress: Block Address for read operation
  * @param  uLength: Length for read operation
  * @retval uResult: TRUE or FALSE
  ***********************************************************************************************************/
u32 SDDISK_Read(u32 uId, u8 **pBuffer, u32 uBlockAddress, u32 uLength)
{
  u32 uResult = TRUE;
  SD_Error errorstatus;
  if (uId == SDDISK0_ID)
  {
    if ((uBlockAddress / CACHE_CNT != uCachePage / CACHE_CNT) && (uCachePage != uBlockAddress))
    {
      /* Calculate the cache start address which shall be aligned with the cache size.                      */
      uCachePage = (uBlockAddress / CACHE_CNT) * CACHE_CNT;
      errorstatus = SD_ReadMultiBlocks(&SDCardInfo, uCachePage * SDDISK0_BlockSize, (u32*)guReadBuffer,SDDISK0_BlockSize , CACHE_CNT);
      if (errorstatus != SD_OK)
      {
        printf("Read Error[%d]\r\n",errorstatus);
        uResult = FALSE;
      }
    }
    if ((uCurrentBlock != uBlockAddress) || ((guReadBufferOffset % SDDISK0_BlockSize) == 0))
    {
      uCurrentBlock = uBlockAddress;
      guReadBufferOffset = (uBlockAddress - uCachePage) * SDDISK0_BlockSize;
    }
    *pBuffer = &(guReadBuffer[guReadBufferOffset]);
    guReadBufferOffset += BOT_MAX_PACKET_SIZE;
  }
  else
  {
    uResult = FALSE;
  }
  return uResult;
}

/*********************************************************************************************************//**
  * @brief  Write to SD Disk memory.
  * @param  uId: SD Disk ID
  * @param  pBuffer: Pointer of data buffer
  * @param  uBlockAddress: Block Address for write operation
  * @param  uLength: Length for write operation
  * @retval uResult: TRUE or FALSE
  ***********************************************************************************************************/
u32 SDDISK_Write(u32 uId, u8 *pBuffer, u32 uBlockAddress, u32 uLength)
{
  u32 i;
  u32 uResult = TRUE;
  SD_Error errorstatus;
  if (uId == SDDISK0_ID)
  {
    uResult = TRUE;
    if (gDiskWriteStatus == SDDISK_IDLE)
    {
      gDiskWriteStatus = SDDISK_WRITE;
      guWriteBufferOffset = 0;
    }
    for (i = 0; i < uLength; i++)
    {
      guWriteBuffer[guWriteBufferOffset + i] = *(pBuffer + i);
    }
    guWriteBufferOffset += uLength;
    if (guWriteBufferOffset == SDDISK0_BlockSize)
    {
      gDiskWriteStatus = SDDISK_IDLE;
      errorstatus = SD_WriteBlock(&SDCardInfo, uBlockAddress*512, (u32*)guWriteBuffer, SDDISK0_BlockSize);
      if (errorstatus != SD_OK)
      {
        printf("Write Error[%d]\r\n",errorstatus);
        uResult = FALSE;
      }
    }
  }
  else
  {
    uResult = FALSE;
  }

  return uResult;
}

/*********************************************************************************************************//**
  * @brief  Get SD Disk Status.
  * @param  uId: SD Disk ID
  * @param  pSizeInfo: Pointer of media size information
  * @retval uResult: TRUE means disk ready for access. FALSE for disk not ready
  ***********************************************************************************************************/
u32 SDDISK_Init(u32 uId, BOT_MediaSize_Typedef *pSizeInfo)
{
  SD_Error errorstatus;
  u32 uResult = TRUE;
  u32 uSizeMul;

  if (bSDDiskUnload)
  {
    return FALSE;
  }

  /*
    SDIO: D0~D3 & CMD pin, should be pull-up 10K
  */
  errorstatus = SD_Init(&SDCardInfo);
  if (errorstatus != SD_OK)
  {
    printf("\nSD Init fail: %d", errorstatus);
    uResult = FALSE;
  }
  else
  {
    NVIC_EnableIRQ(SDIO_IRQn);
    NVIC_EnableIRQ(PDMACH6_IRQn);   // SDIO_RX
    NVIC_EnableIRQ(PDMACH7_IRQn);   // SDIO_TX

    errorstatus = SD_GetSDStatus(&SDCardInfo);
    if (errorstatus != SD_OK)
    {
      printf("\nSD Get Status fail: %d", errorstatus);
    }

    if (SDCardInfo.CardType == SDIO_HIGH_CAPACITY_SD_CARD)
    {
      printf("Card mode\t[SDHC]\r\n");
      pSizeInfo->uBlockSize = SDDISK0_BlockSize;
      pSizeInfo->uBlockCount = (SDCardInfo.SD_csd.DeviceSize +1) * 512 * 2;
    }
    else
    {
      u8 _DeviceSizeMul;
      u8 _RdBlockLen;
      printf("Card mode\t[SD]\r\n");
      pSizeInfo->uBlockSize = SDDISK0_BlockSize;
      _DeviceSizeMul = SDCardInfo.SD_csd.DeviceSizeMul;
      _RdBlockLen = SDCardInfo.SD_csd.RdBlockLen;
      uSizeMul = (1 << (_DeviceSizeMul + 2)) * ((1 << _RdBlockLen) / SDDISK0_BlockSize);
      pSizeInfo->uBlockCount = (SDCardInfo.SD_csd.DeviceSize + 1) * uSizeMul;
    }
  }

  return uResult;
}

/*********************************************************************************************************//**
  * @brief  Get SD Disk Status.
  * @param  uId: SD Disk ID
  * @param  pSizeInfo: Pointer of media size information
  * @retval uResult: TRUE means disk ready for access. FALSE for disk not ready
  ***********************************************************************************************************/
u32 SDDISK_GetStatus(u32 uId, BOT_MediaSize_Typedef *pSizeInfo)
{
  u32 uResult = TRUE;
  u32 uSizeMul;
  if (bSDDiskUnload)
  {
    return FALSE;
  }
  if (SDCardInfo.CardType == SDIO_HIGH_CAPACITY_SD_CARD)
  {
      pSizeInfo->uBlockSize = SDDISK0_BlockSize;
      pSizeInfo->uBlockCount = (SDCardInfo.SD_csd.DeviceSize +1) * 512 * 2;
  }
  else
  {
      u8 _DeviceSizeMul;
      u8 _RdBlockLen;
      pSizeInfo->uBlockSize = SDDISK0_BlockSize;
      _DeviceSizeMul = SDCardInfo.SD_csd.DeviceSizeMul;
      _RdBlockLen = SDCardInfo.SD_csd.RdBlockLen;
      uSizeMul = (1 << (_DeviceSizeMul + 2)) * ((1 << _RdBlockLen) / SDDISK0_BlockSize);
      pSizeInfo->uBlockCount = (SDCardInfo.SD_csd.DeviceSize + 1) * uSizeMul;
  }
  return uResult;
}

/*********************************************************************************************************//**
  * @brief  Unmount SD Disk.
  * @param  uId: RAM Disk ID
  ***********************************************************************************************************/
void SDDISK_Unmount(u32 uId)
{
  bSDDiskUnload = TRUE;
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
