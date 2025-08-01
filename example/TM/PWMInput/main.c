/*********************************************************************************************************//**
 * @file    TM/PWMInput/main.c
 * @version $Rev:: 2145         $
 * @date    $Date:: 2020-07-30 #$
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

/** @addtogroup TM_Examples TM
  * @{
  */

/** @addtogroup PWMInput
  * @{
  */


/* Private variables ---------------------------------------------------------------------------------------*/
extern vu32 wDutyCycle;
extern vu32 wFrequency;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  * @note At this stage the microcontroller clock setting is already configured,
  *       this is done through SystemInit() function which is called from startup
  *       file (startup_ht32fxxxx.s) before branching to application main.
  *       To reconfigure the default setting of SystemInit() function, refer to
  *       system_ht32fxxxx.c file
  * @details Main program as following
  *  - USART Related configuration.
  *  - Config PA1 with internal pull-high resistor.
  *  - Config AFIO mode of HTCFG_INPUT_PWM_TM_CHANNEL and HTCFG_OUTPUT_PWM_TM_CHANNEL as TM function
  *  - Enable HTCFG_INPUT_PWM_TM and HTCFG_OUTPUT_PWM_TM PCLK
  *  - Configures HTCFG_OUTPUT_PWM_TM Channel1 to output PWM signal.
  *    - wFrequency = 2 kHz
  *    - wDutyCycle = 33 %.
  *  - HTCFG_INPUT_PWM_TM is configured in PWM Input Mode.
  *    - The TM frequency is set to 72 MHz or 80 MHz or 96 MHz, the Prescaler is 0
  *      so the TM_CounterClock = (TM_PCLK / (0 + 1).
  *      so the minimum frequency value to measure is TM_PCLK/65536.
  *    - The external signal is connected to HTCFG_INPUT_PWM_TM Channel1 used as input pin.
  *    - The HTCFG_INPUT_PWM_TM CH1CCR is used to compute the frequency value.
  *    - The HTCFG_INPUT_PWM_TM CH0CCR is used to compute the duty cycle value.
  *  - The HTCFG_INPUT_PWM_TM is configured as slave restart mode.
  *    - The trigger source is come from TI1S1
  *    - Enable the UGDIS function. Only counter overflow assert Update Event interrupt.
  *      The Slave Restart or setting the UEVG bit does not assert Update Event.
  *  - Enable HTCFG_INPUT_PWM_TM.
  *  - Enable HTCFG_INPUT_PWM_TM Channel 1 Capture interrupt and Update Event interrupt.
  *    Please refer to HTCFG_INPUT_PWM_IRQHandler for details.
  *  - Print wFrequency and wDutyCycle via USART.
  *
  ***********************************************************************************************************/
int main(void)
{
  /* !!! NOTICE !!!
     Notice that the local variable (structure) did not have an initial value.
     Please confirm that there are no missing members in the parameter settings below in this function.
  */
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
  TM_TimeBaseInitTypeDef TimeBaseInit;
  TM_OutputInitTypeDef OutInit;
  TM_CaptureInitTypeDef  CapInit;
  u32 wCRR = 0;

  RETARGET_Configuration();           /* Retarget Related configuration                                     */

  HTCFG_INPUT_PWM_TM_GPIO_CLK(CKCUClock)         = 1;
  CKCUClock.Bit.AFIO                             = 1;
  HTCFG_INPUT_PWM_TM_CLK(CKCUClock)              = 1;
  HTCFG_OUTPUT_PWM_TM_CLK(CKCUClock)             = 1;
  CKCU_PeripClockConfig(CKCUClock, ENABLE);

  /* Config with internal pull-high resistor                                                                */
  GPIO_PullResistorConfig(HTCFG_INPUT_PWM_TM_GPIO, HTCFG_INPUT_PWM_TM_GPIO_PIN, GPIO_PR_UP);

  /* Config AFIO mode of GT0_CH1 and GT1_CH1 as GPTM function                                               */
  AFIO_GPxConfig(HTCFG_OUTPUT_PWM_TM_GPIO_ID, HTCFG_OUTPUT_PWM_TM_AFIO_PIN, HTCFG_OUTPUT_PWM_TM_AFIO_FUN);
  AFIO_GPxConfig(HTCFG_INPUT_PWM_TM_GPIO_ID, HTCFG_INPUT_PWM_TM_AFIO_PIN, HTCFG_INPUT_PWM_TM_AFIO_FUN);

  /* GPTM0 Time-Base configuration                                                                          */
  wCRR = (SystemCoreClock / 2000) - 1;
  TM_TimeBaseStructInit(&TimeBaseInit);
  TimeBaseInit.CounterMode = TM_CNT_MODE_UP;
  TimeBaseInit.CounterReload = wCRR;
  TimeBaseInit.Prescaler = 0;
  TimeBaseInit.RepetitionCounter = 0;
  TimeBaseInit.PSCReloadTime = TM_PSC_RLD_UPDATE;
  TM_TimeBaseInit(HTCFG_OUTPUT_PWM_TM, &TimeBaseInit);

  /* GPTM0 Channel 1 output configuration                                                                   */
  TM_OutputStructInit(&OutInit);
  OutInit.Channel = HTCFG_OUTPUT_PWM_TM_CHANNEL;
  OutInit.OutputMode = TM_OM_PWM1;
  OutInit.Control = TM_CHCTL_ENABLE;
  OutInit.Polarity = TM_CHP_NONINVERTED;
  OutInit.Compare = ((wCRR + 1) * 33) / 100;
  TM_OutputInit(HTCFG_OUTPUT_PWM_TM, &OutInit);

  /* Enable GPTM0                                                                                           */
  TM_Cmd(HTCFG_OUTPUT_PWM_TM, ENABLE);

  /* GPTM1 PWM input mode configuration                                                                     */
  TM_CaptureStructInit(&CapInit);
  CapInit.Channel = HTCFG_INPUT_PWM_TM_CHANNEL;
  CapInit.Polarity = TM_CHP_NONINVERTED;
  CapInit.Selection = TM_CHCCS_DIRECT;
  CapInit.Prescaler = TM_CHPSC_OFF;
  CapInit.Filter = 0x0;

  TM_PwmInputInit(HTCFG_INPUT_PWM_TM, &CapInit);

  /**
   * The trigger source is come from TI1S1
   * The GPTM1 is configured as slave restart mode.
   */
  TM_StiConfig(HTCFG_INPUT_PWM_TM, TM_TRSEL_TI1S1);
  TM_SlaveModeConfig(HTCFG_INPUT_PWM_TM, TM_SMSEL_RESTART);

  /* Enable the UGDIS function                                                                              */
  TM_UEVG_IntConfig(HTCFG_INPUT_PWM_TM, DISABLE);

  /* Enable GPTM1                                                                                           */
  TM_Cmd(HTCFG_INPUT_PWM_TM, ENABLE);

  /* Enable GPTM1 Channel 1 Capture interrupt and Update Event interrupt                                    */
  NVIC_EnableIRQ(HTCFG_INPUT_PWM_IRQ);
  TM_IntConfig(HTCFG_INPUT_PWM_TM, HTCFG_INPUT_PWM_INT_CHX | TM_INT_UEV, ENABLE);

  /* Print wFrequency and wDutyCycle via USART                                                              */
  while (1)
  {
    unsigned int wDutyCycleInteger = wDutyCycle >> 16;
    unsigned int wDutyCycleFraction = ((wDutyCycle & 0xFFFF) * 10000) / 0x10000;

    printf("wFrequency %u Hz, wDutyCycle %u.%04u %%                  \r",
      (unsigned int)wFrequency, wDutyCycleInteger, wDutyCycleFraction );
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
