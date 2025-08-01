/*********************************************************************************************************//**
 * @file    IP/Example/main.c
 * @version $Rev:: 3144         $
 * @date    $Date:: 2024-07-05 #$
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
// <<< Use Configuration Wizard in Context Menu >>>

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"

/** @addtogroup Project_Template Project Template
  * @{
  */

/** @addtogroup IP_Examples IP
  * @{
  */

/** @addtogroup Example
  * @{
  */


/* Settings ------------------------------------------------------------------------------------------------*/
/* Private types -------------------------------------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------------------------------------*/
void NVIC_Configuration(void);
void CKCU_Configuration(void);
void GPIO_Configuration(void);
#if (ENABLE_CKOUT == 1)
void CKOUTConfig(void);
#endif

static void __Delay(u32 count);

/* Private macro -------------------------------------------------------------------------------------------*/
/* Global variables ----------------------------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------------------------------------*/
/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
  s32 input;

  #if (HTCFG_STACK_USAGE_ANALYSIS == 1)
  /* !!! NOTICE !!!
     Please update the Keil HT32 PACK and HT32 Firmware Library to the latest version to make sure the
     Stack Usage Analysis function works properly.
  */
  /*
    Set HTCFG_STACK_USAGE_ANALYSIS as 1 in the "ht32xxxxxx_conf.h" to enable Stack Usage Analysis feature.
    This feature is only applicable to the Keil MDK-ARM. Please call the "StackUsageAnalysisInit()" function
    in the begin of the "main()".
    The "StackUsageAnalysisInit()" parameter shall be the start address of the vector table.
    Under Keil Debug mode, tick "View > Watch Window > HT32 Stack Usage Analysis" to show the stack usage
    information. Those information is only valid after calling "StackUsageAnalysisInit()" function.
  */
  StackUsageAnalysisInit(0x00000000);
  #endif

  NVIC_Configuration();               /* NVIC configuration                                                 */
  CKCU_Configuration();               /* System Related configuration                                       */
  GPIO_Configuration();               /* GPIO Related configuration                                         */
  RETARGET_Configuration();           /* Retarget Related configuration                                     */

  HT32F_DVB_LEDInit(HT_LED1);
  HT32F_DVB_LEDInit(HT_LED2);
  HT32F_DVB_LEDInit(HT_LED3);
  HT32F_DVB_LEDOn(HT_LED1);
  HT32F_DVB_LEDOff(HT_LED2);
  HT32F_DVB_LEDOn(HT_LED3);

  for (input = 0; input < 10; input++)
  {
    __Delay(4000000);
    HT32F_DVB_LEDToggle(HT_LED1);
    HT32F_DVB_LEDToggle(HT_LED2);
    HT32F_DVB_LEDToggle(HT_LED3);
  }

  for (input = 0; input < 100; input++)
  {
    printf("Hello World! %d\r\n", input);
  }

  while (1)                           /* Infinite loop                                                      */
  {
    printf("Please input key for printf....");
    SERIAL_Flush();

    input = getchar();
    printf("\r\nYour input is %c[0x%x]\r\n\r\n", input, input);
    SERIAL_Flush();

    HT32F_DVB_LEDToggle(HT_LED1);
    HT32F_DVB_LEDToggle(HT_LED2);
    HT32F_DVB_LEDToggle(HT_LED3);
  }
}

/*********************************************************************************************************//**
  * @brief  Configure the NVIC vector table.
  * @retval None
  ***********************************************************************************************************/
void NVIC_Configuration(void)
{
  NVIC_SetVectorTable(NVIC_VECTTABLE_FLASH, 0x0);     /* Set the Vector Table base location at 0x00000000   */
}

/*********************************************************************************************************//**
  * @brief  Configure the system clocks.
  * @retval None
  ***********************************************************************************************************/
void CKCU_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.USART0     = 1;
  CKCUClock.Bit.USART1     = 1;
  CKCUClock.Bit.UART0      = 1;
  CKCUClock.Bit.UART1      = 1;
  CKCUClock.Bit.AFIO       = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

#if (ENABLE_CKOUT == 1)
  CKOUTConfig();
#endif
}

#if (ENABLE_CKOUT == 1)
/*********************************************************************************************************//**
  * @brief  Configure the debug output clock.
  * @retval None
  ***********************************************************************************************************/
void CKOUTConfig(void)
{
  { /* Enable peripheral clock                                                                              */
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.AFIO = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }

  AFIO_GPxConfig(GPIO_PA, AFIO_PIN_8, AFIO_MODE_15);

  { /* Configure CKOUT                                                                                      */
    CKCU_CKOUTInitTypeDef CKOUTInit;
    CKOUTInit.CKOUTSRC = CKCU_CKOUTSRC_HCLK_DIV16;
    CKCU_CKOUTConfig(&CKOUTInit);
  }
}
#endif

/*********************************************************************************************************//**
  * @brief  Configure the GPIO ports.
  * @retval None
  ***********************************************************************************************************/
void GPIO_Configuration(void)
{
  /* !!! NOTICE !!!
     Shall be modified according to the part number.
  */
#if (RETARGET_PORT == RETARGET_USART0)
  //AFIO_GPxConfig(GPIO_PA, AFIO_PIN_2 | AFIO_PIN_3, AFIO_FUN_USART_UART);
#endif

#if (RETARGET_PORT == RETARGET_USART1)
  //AFIO_GPxConfig(GPIO_PA, AFIO_PIN_4 | AFIO_PIN_5, AFIO_FUN_USART_UART);
#endif

#if (RETARGET_PORT == RETARGET_UART0)
  //AFIO_GPxConfig(GPIO_PC, AFIO_PIN_4 | AFIO_PIN_5, AFIO_FUN_USART_UART);
#endif

#if (RETARGET_PORT == RETARGET_UART1)
  //AFIO_GPxConfig(GPIO_PC, AFIO_PIN_1 | AFIO_PIN_3, AFIO_FUN_USART_UART);
#endif
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

/* Private functions ---------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  delay function
  * @param  count: delay count for loop
  * @retval None
  ***********************************************************************************************************/
static void __Delay(u32 count)
{
  while (count--)
  {
    __NOP(); // Prevent delay loop be optimized
  }
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
