/*********************************************************************************************************//**
 * @file    I2S/CodecLoopback_PDMA/i2cm.h
 * @version $Rev:: 2136         $
 * @date    $Date:: 2020-07-17 #$
 * @brief   The header file of I2C master driver.
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

/* Define to prevent recursive inclusion -------------------------------------------------------------------*/
#ifndef __I2CM_H
#define __I2CM_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board_config.h"

/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup I2S_Examples I2S
  * @{
  */

/** @addtogroup CodecLoopback_PDMA
  * @{
  */


#define I2CM_SPEED    (400000)

#define I2CM_DelayXuS Delay_XuS

/* Exported types ------------------------------------------------------------------------------------------*/
typedef struct
{
  u8 DevAddr;
  u8 RegAddrMode;
  u8 Direction;
  vu8 Status;
  u16 RegAddr;
  u16 Length;
  u16 Counter;
  u16 RetryDownCounter;
  void (*TransferEndCallback)(void);
  u8* Buffer;
  u8 IsConfigured;
  bool IsRegAddrSent;
} I2CM_TransferType;

/* Exported constants --------------------------------------------------------------------------------------*/
#define I2CM_OK                     0
#define I2CM_BUSY                   1
#define I2CM_SLAVE_NO_RESPONSE      2
#define I2CM_BUFFER_NULL            3
#define I2CM_ARBLOS                 4   /*!< I2C transfer status : Error caused by Arbitration Loss         */
#define I2CM_BUSERR                 5   /*!< I2C transfer status : Error caused by bus error                */
#define I2CM_TOUTF                  6

#define I2CM_WORD_ADDR_MODE_1BYTE   0
#define I2CM_WORD_ADDR_MODE_2BYTE   1

#define I2CM_OWN_ADDR       (0x00)
#define I2CM_BUS_MAX_RETRY  (0xFF)

#define I2CM_DIRECTION_OUT   0
#define I2CM_DIRECTION_IN    1

#define I2CM_DBGEN  (0)

#if (I2CM_DBGEN != 0)
  #define I2CM_DBG_PRINTF printf
#else
  #define I2CM_DBG_PRINTF(...)
#endif

/* Exported functions --------------------------------------------------------------------------------------*/
void I2CM_Init(void);
void I2CM_WordAddressModeConfig(u32 word_addr_mode);
void I2CM_InstallTransferEndCallback(void (*callback)(void));
void I2CM_UninstallTransferEndCallback(void);
void I2CM_BufferRead(u16 dev, u16 word_addr, u8* data, u16 count);
void I2CM_BufferWrite(u16 dev, u16 word_addr, u8* data, u16 count);
u32 I2CM_GetTransferStatus(void);
ErrStatus I2CM_WaitTransferEnd(void);
ErrStatus I2CM_BlockedBufferRead(u16 dev, u16 word_addr, u8* data, u16 count);
ErrStatus I2CM_BlockedBufferWrite(u16 dev, u16 word_addr, u8* data, u16 count);


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif

