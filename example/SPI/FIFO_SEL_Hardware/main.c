/*********************************************************************************************************//**
 * @file    SPI/FIFO_SEL_Hardware/main.c
 * @version $Rev:: 2353         $
 * @date    $Date:: 2021-02-25 #$
 * @brief   Main program.
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
#include "ht32.h"
#include "ht32_board.h"
#include "ht32_board_config.h"

/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup SPI_Examples SPI
  * @{
  */

/** @addtogroup FIFO_SEL_Hardware
  * @{
  */


/* Private types -------------------------------------------------------------------------------------------*/
typedef enum {Fail = 0, Pass = !Fail} TestResult;

/* Private constants ---------------------------------------------------------------------------------------*/
#define BufferSize             12

/* Private function prototypes -----------------------------------------------------------------------------*/
TestResult CmpBuffer(u8* Buffer1, u8* Buffer2, u32 BufferLength);

/* Private variables ---------------------------------------------------------------------------------------*/
SPI_InitTypeDef SPI_InitStructure;

u8 SPI0_Buffer_Tx[BufferSize] = {0x11, 0x22, 0x33, 0x44,
                                 0x55, 0x66, 0x77, 0x88,
                                 0x99, 0xAA, 0xBB, 0xCC};

u8 SPI1_Buffer_Tx[BufferSize] = {0xCC, 0xBB, 0xAA, 0x99,
                                 0x88, 0x77, 0x66, 0x55,
                                 0x44, 0x33, 0x22, 0x11};

u8 SPI0_Buffer_Rx[BufferSize] = {0};
u8 SPI1_Buffer_Rx[BufferSize] = {0};
vu8 Tx_Index = 0, SPI0_Rx_Index = 0, SPI1_Rx_Index = 0, tmpflag = 0;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};

  /* Initialize LED1 & LED2 on HT32 board                                                                   */
  HT32F_DVB_LEDInit(HT_LED1);
  HT32F_DVB_LEDInit(HT_LED2);

  /* Enable NVIC SPI0 & SPI1 interrupt                                                                      */
  NVIC_EnableIRQ(SPI0_IRQn);
  NVIC_EnableIRQ(SPI1_IRQn);

  /* Enable PA, SPI0, SPI1 & AFIO clock                                                                     */
  HTCFG_SPI_MASTER_SEL_CLOCK(CKCUClock)   = 1;
  CKCUClock.Bit.SPI0                      = 1;
  CKCUClock.Bit.SPI1                      = 1;
  CKCUClock.Bit.AFIO                      = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  /* SPI0_SEL idle state is HIGH                                                                            */
  GPIO_PullResistorConfig(HTCFG_SPI_ENABLE_ID, HTCFG_SPI_MASTER_SEL_GPIO_PIN, GPIO_PR_UP);

  /* Configure related IO to SPI0 mode                                                                      */
  AFIO_GPxConfig(HTCFG_SPI_MASTER_SEL_AFIO_PORT, HTCFG_SPI_MASTER_SEL_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_MASTER_SCK_AFIO_PORT, HTCFG_SPI_MASTER_SCK_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_MASTER_MOSI_AFIO_PORT, HTCFG_SPI_MASTER_MOSI_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_MASTER_MISO_AFIO_PORT, HTCFG_SPI_MASTER_MISO_AFIO_PIN, AFIO_MODE_5);

  /* Configure related IO to SPI1 mode                                                                      */
  AFIO_GPxConfig(HTCFG_SPI_SLAVE_SEL_AFIO_PORT, HTCFG_SPI_SLAVE_SEL_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_SLAVE_SCK_AFIO_PORT, HTCFG_SPI_SLAVE_SCK_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_SLAVE_MOSI_AFIO_PORT, HTCFG_SPI_SLAVE_MOSI_AFIO_PIN, AFIO_MODE_5);
  AFIO_GPxConfig(HTCFG_SPI_SLAVE_MISO_AFIO_PORT, HTCFG_SPI_SLAVE_MISO_AFIO_PIN, AFIO_MODE_5);

  /* SPI0 configuration: Master mode                                                                        */
  SPI_InitStructure.SPI_Mode = SPI_MASTER;
  SPI_InitStructure.SPI_FIFO = SPI_FIFO_ENABLE;
  SPI_InitStructure.SPI_DataLength = SPI_DATALENGTH_8;
  SPI_InitStructure.SPI_SELMode = SPI_SEL_HARDWARE;
  SPI_InitStructure.SPI_SELPolarity = SPI_SELPOLARITY_LOW;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_LOW;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_FIRST;
  SPI_InitStructure.SPI_FirstBit = SPI_FIRSTBIT_MSB;
  SPI_InitStructure.SPI_RxFIFOTriggerLevel = 4;
  SPI_InitStructure.SPI_TxFIFOTriggerLevel = 4;
  SPI_InitStructure.SPI_ClockPrescaler = 8;
  SPI_Init(HT_SPI0, &SPI_InitStructure);

  /* SPI1 configuration: Slave mode                                                                         */
  SPI_InitStructure.SPI_Mode = SPI_SLAVE;
  SPI_Init(HT_SPI1, &SPI_InitStructure);

  /* Set SEL as output mode for slave select                                                                */
  SPI_SELOutputCmd(HT_SPI0, ENABLE);

  /* Enable SPI0 & SPI1 RXBNE interrupt                                                                     */
  SPI_IntConfig(HT_SPI0, SPI_INT_RXBNE | SPI_INT_TOUT, ENABLE);
  SPI_IntConfig(HT_SPI1, SPI_INT_RXBNE | SPI_INT_TOUT, ENABLE);

  /* Setting TimeOut Counter                                                                                */
  SPI_SetTimeOutValue(HT_SPI0, 0xFFFF);
  SPI_SetTimeOutValue(HT_SPI1, 0xFFFF);

  /* Enable slave first                                                                                     */
  SPI_Cmd(HT_SPI1, ENABLE);
  /* Enable master later                                                                                    */
  SPI_Cmd(HT_SPI0, ENABLE);

  /* Send data ---------------------------------------------------------------------------------------------*/
  while (Tx_Index < BufferSize)
  {
    /* Check on SPI1 Tx Buffer empty                                                                        */
    while (!SPI_GetFlagStatus(HT_SPI1, SPI_FLAG_TXBE));
    /* Send SPI1 data                                                                                       */
    SPI_SendData(HT_SPI1, SPI1_Buffer_Tx[Tx_Index]);
    /* Check on SPI0 Tx Buffer empty                                                                        */
    while (!SPI_GetFlagStatus(HT_SPI0, SPI_FLAG_TXBE));
    /* Send SPI0 data                                                                                       */
    SPI_SendData(HT_SPI0, SPI0_Buffer_Tx[Tx_Index ++]);
  }

  /* Wait for transmission finished                                                                         */
  while (tmpflag != 6);

  /* Check on validity of received data on SPI0 & SPI1                                                      */
  if (CmpBuffer(SPI0_Buffer_Tx, SPI1_Buffer_Rx, BufferSize) && CmpBuffer(SPI1_Buffer_Tx, SPI0_Buffer_Rx, BufferSize))
  {
    /* Turn on LED1 if the transmitted and received data are equal                                          */
    HT32F_DVB_LEDOn(HT_LED1);
  }
  else
  {
    /* Turn on LED2 if the transmitted and received data are different                                      */
    HT32F_DVB_LEDOn(HT_LED2);
  }

  while (1);
}

/*********************************************************************************************************//**
  * @brief  Compare two buffers.
  * @param  Buffer1, Buffer2: buffers to be compared.
  * @param  BufferLength: buffer's length
  * @retval None
  ***********************************************************************************************************/
TestResult CmpBuffer(u8* Buffer1, u8* Buffer2, u32 BufferLength)
{
  while (BufferLength--)
  {
    if (*Buffer1 != *Buffer2)
    {
      return Fail;
    }

    Buffer1++;
    Buffer2++;
  }

  return Pass;
}

#if (HT32_LIB_DEBUG == 1)
/*********************************************************************************************************//**
  * @brief  Report both the error name of the source file and the source line number.
  * @param  filename: pointer to the source file name.
  * @param  uline: error line source number.
  * @retval None
  ***********************************************************************************************************/
void assert_error(u8* filename, u32 uline)
{
  /*
     This function is called by IP library that the invalid parameters has been passed to the library API.
     Debug message can be added here.
     Example: printf("Parameter Error: file %s on line %d\r\n", filename, uline);
  */

  while (1)
  {
  }
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
