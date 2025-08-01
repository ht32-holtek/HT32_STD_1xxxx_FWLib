/*********************************************************************************************************//**
 * @file    USART/Interrupt_FIFO/main.c
 * @version $Rev:: 2236         $
 * @date    $Date:: 2020-11-05 #$
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

/** @addtogroup USART_Examples USART
  * @{
  */

/** @addtogroup Interrupt_FIFO
  * @{
  */


/* Private function prototypes -----------------------------------------------------------------------------*/
void UxART_Configuration(void);
void UxART_TxTest(void);
void UxART_RxTest(void);

/* Global variables ----------------------------------------------------------------------------------------*/
uc8  *gURTx_Ptr;
vu32 gURTx_Length = 0;
u8  *gURRx_Ptr;
vu32 gURRx_Length = 0;

vu32 gIsTxFinished = FALSE;

/* Private variables ---------------------------------------------------------------------------------------*/
uc8 gHelloString[] = "Hello, this is USART Tx/Rx FIFO example. Please enter 5 characters...\r\n";
u8 gTx_Buffer[128];
u8 gRx_Buffer[128];

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  * @details Main program as following
  *  - Configure the IP Clock, AFIO, and USART IP including FIFO Level and Rx Timeout.
  *  - Send HelloString.
  *  - Waiting Rx for receive 5 data, and then loop back Rx data to Tx for test.
  ***********************************************************************************************************/
int main(void)
{
  HT32F_DVB_LEDInit(HT_LED1);
  HT32F_DVB_LEDInit(HT_LED2);

  gURRx_Ptr = gRx_Buffer;

  UxART_Configuration();

  UxART_TxTest();

  while (1)
  {
    UxART_RxTest();
  }
}

/*************************************************************************************************************
  * @brief  Configure the UxART
  * @retval None
  ***********************************************************************************************************/
void UxART_Configuration(void)
{
  #if 0 // Use following function to configure the IP clock speed.
  // The UxART IP clock speed must be faster 16x then the baudrate.
  CKCU_SetPeripPrescaler(CKCU_PCLK_UxARTn, CKCU_APBCLKPRE_DIV2);
  #endif

  { /* Enable peripheral clock of AFIO, UxART                                                               */
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
    CKCUClock.Bit.AFIO                   = 1;
    CKCUClock.Bit.HTCFG_UART_RX_GPIO_CLK = 1;
    CKCUClock.Bit.HTCFG_UART_IPN         = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }

  /* Turn on UxART Rx internal pull up resistor to prevent unknow state                                     */
  GPIO_PullResistorConfig(HTCFG_UART_RX_GPIO_PORT, HTCFG_UART_RX_GPIO_PIN, GPIO_PR_UP);

  /* Config AFIO mode as UxART function.                                                                    */
  AFIO_GPxConfig(HTCFG_UART_TX_GPIO_ID, HTCFG_UART_TX_AFIO_PIN, AFIO_FUN_USART_UART);
  AFIO_GPxConfig(HTCFG_UART_RX_GPIO_ID, HTCFG_UART_RX_AFIO_PIN, AFIO_FUN_USART_UART);

  {
    /* UxART configured as follow:
          - BaudRate = 115200 baud
          - Word Length = 8 Bits
          - One Stop Bit
          - None parity bit
    */

    /* !!! NOTICE !!!
       Notice that the local variable (structure) did not have an initial value.
       Please confirm that there are no missing members in the parameter settings below in this function.
    */
    USART_InitTypeDef USART_InitStructure = {0};
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WORDLENGTH_8B;
    USART_InitStructure.USART_StopBits = USART_STOPBITS_1;
    USART_InitStructure.USART_Parity = USART_PARITY_NO;
    USART_InitStructure.USART_Mode = USART_MODE_NORMAL;
    USART_Init(HTCFG_UART_PORT, &USART_InitStructure);
  }

  /* Enable UxART interrupt of NVIC                                                                         */
  NVIC_EnableIRQ(HTCFG_UART_IRQn);

  /* Enable UxART Rx interrupt                                                                              */
  USART_IntConfig(HTCFG_UART_PORT, USART_INT_RXDR, ENABLE);

  /* Enable UxART Timeout interrupt                                                                         */
  USART_IntConfig(HTCFG_UART_PORT, USART_INT_TOUT, ENABLE);

  /* Seting Tx/Rx FIFO Level                                                                                */
  USART_RXTLConfig(HTCFG_UART_PORT, USART_RXTL_04);
  USART_TXTLConfig(HTCFG_UART_PORT, USART_TXTL_02);

  /*Seting TimeOut Counter                                                                                  */
  USART_SetTimeOutValue(HTCFG_UART_PORT, 0x7F);

  /* Enable UxART Tx and Rx function                                                                        */
  USART_TxCmd(HTCFG_UART_PORT, ENABLE);
  USART_RxCmd(HTCFG_UART_PORT, ENABLE);
}

/*********************************************************************************************************//**
  * @brief  UxART Tx Test.
  * @retval None
  ***********************************************************************************************************/
void UxART_TxTest(void)
{
  gIsTxFinished = FALSE;
  gURTx_Ptr = (u8 *)gHelloString;
  gURTx_Length = sizeof(gHelloString) - 1;

  #if (LIBCFG_USART_V01)
  USART_IntConfig(HTCFG_UART_PORT, USART_INT_TXDE, ENABLE);
  #else
  USART_IntConfig(HTCFG_UART_PORT, USART_INT_TXDE | USART_INT_TXC, ENABLE);
  #endif

  while (gURTx_Length != 0);      // Latest byte move to UxART shift register, but the transmission may be on going.

  #if (LIBCFG_USART_V01)
  while (USART_GetFlagStatus(HTCFG_UART_PORT, USART_FLAG_TXC) == RESET);
  #else
  while (gIsTxFinished == FALSE); // Set by TXC interrupt, transmission is finished.
  #endif
}

/*********************************************************************************************************//**
  * @brief  UxART Rx Test.
  * @retval None
  ***********************************************************************************************************/
void UxART_RxTest(void)
{
  u32 i;
  u32 uLength;

  /* Waiting for receive 5 data                                                                             */
  if (gURRx_Length >= 5)
  {
    // Process Rx data by gRx_Buffer[] and gURRx_Length here
    // .....

    uLength = gURRx_Length;
    for (i = 0; i < uLength; i++)
    {
      gTx_Buffer[i] = gRx_Buffer[i];
    }

    #if 1 // Loop back Rx data to Tx for test
    gIsTxFinished = FALSE;
    gURTx_Ptr = gTx_Buffer;
    gURTx_Length = uLength;
    #if (LIBCFG_USART_V01)
    USART_IntConfig(HTCFG_UART_PORT, USART_INT_TXDE, ENABLE);
    #else
    USART_IntConfig(HTCFG_UART_PORT, USART_INT_TXDE | USART_INT_TXC, ENABLE);
    #endif
    #endif

    gURRx_Length = 0;
  }
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
