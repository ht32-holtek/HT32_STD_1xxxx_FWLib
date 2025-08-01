/*********************************************************************************************************//**
 * @file    PWRCU/PowerDown_WAKEUPPin/main.c
 * @version $Rev:: 2869         $
 * @date    $Date:: 2023-02-20 #$
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
#include "ht32_board_Config.h"

/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup PWRCU_Examples PWRCU
  * @{
  */

/** @addtogroup PowerDown_WAKEUPPin
  * @{
  */


/* Private function prototypes -----------------------------------------------------------------------------*/
void LowPower_BootCheck(void);
void LowPower_WAKEUPPin_Configuration(void);
void LowPower_Enter(void);

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
  vu32 i;

  RETARGET_Configuration();

  LowPower_BootCheck();
  LowPower_WAKEUPPin_Configuration();

  HT32F_DVB_LEDInit(HT_LED1);
  HT32F_DVB_LEDInit(HT_LED2);
  HT32F_DVB_LEDInit(HT_LED3);
  HT32F_DVB_LEDOn(HT_LED1);
  HT32F_DVB_LEDOn(HT_LED2);
  HT32F_DVB_LEDOn(HT_LED3);

  while (1)
  {
    for (i = 0; i < 40000000; i++){};

    // If the WAKEUP pin is active, skip the low power mode.
    if (GPIO_ReadInBit(GPIO_PORT[WAKEUP_BUTTON_GPIO_ID], WAKEUP_BUTTON_GPIO_PIN) == SET)
    {
      continue;
    }

    HT32F_DVB_LEDOff(HT_LED1);
    HT32F_DVB_LEDOff(HT_LED2);
    HT32F_DVB_LEDOff(HT_LED3);

    // You shall make sure the WAKEUP pin is inactive before enter the low power mode.
    LowPower_Enter();

    // Never reacher here. Since the system will be restart when wakeup from the Power Down mode.

  }
}

/*********************************************************************************************************//**
  * @brief  Related checking when bootup.
  * @retval None
  ***********************************************************************************************************/
void LowPower_BootCheck(void)
{
  u32 uBAKSR;
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};

  CKCUClock.Bit.BKP        = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  uBAKSR = PWRCU_GetFlagStatus();

  // Must read clear the WAKEUP Pin Flag (WUPF) by PWRCU_GetFlagStatus()
  if ((uBAKSR & (PWRCU_FLAG_WUP | PWRCU_FLAG_PD)) == (PWRCU_FLAG_WUP | PWRCU_FLAG_PD))
  {
    // Means wakeup by WAKEUP pin, do your own process here
    printf("WAKEUP!\r\n");
  }

  /*
  // Since the flags read by PWRCU_GetFlagStatus() are read clear, you must check all the flag here
  if (uBAKSR & PWRCU_FLAG_XXXX)
  {

  }
  */

}

/*********************************************************************************************************//**
  * @brief  EXTI Wakeup configuration.
  * @retval None
  ***********************************************************************************************************/
void LowPower_WAKEUPPin_Configuration(void)
{
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};

  /* Enable EXTI & GPIO IP clock                                                                            */
  CKCUClock.Bit.PC         = 1;
  CKCUClock.Bit.AFIO       = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  /* Configure GPIO pull down, AFIO mode, and Input Enable                                                  */
  AFIO_GPxConfig(WAKEUP_BUTTON_GPIO_ID, WAKEUP_BUTTON_GPIO_PIN, HTCFG_WEAK_UP_AFIO_MODE);
  GPIO_PullResistorConfig(GPIO_PORT[WAKEUP_BUTTON_GPIO_ID], WAKEUP_BUTTON_GPIO_PIN, GPIO_PR_DOWN);
  GPIO_InputConfig(GPIO_PORT[WAKEUP_BUTTON_GPIO_ID], WAKEUP_BUTTON_GPIO_PIN, ENABLE);
}

/*********************************************************************************************************//**
  * @brief  Enter low power mode.
  * @retval None
  ***********************************************************************************************************/
void LowPower_Enter(void)
{
  PWRCU_WakeupPinCmd(ENABLE);

  PWRCU_PowerDown();
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
