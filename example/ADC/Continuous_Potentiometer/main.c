/*********************************************************************************************************//**
 * @file    ADC/Continuous_Potentiometer/main.c
 * @version $Rev:: 2064         $
 * @date    $Date:: 2020-03-02 #$
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

/** @addtogroup ADC_Examples ADC
  * @{
  */

/** @addtogroup Continuous_Potentiometer
  * @{
  */


/* Private function prototypes -----------------------------------------------------------------------------*/
void ADC_Configuration(void);

/* Global variables ----------------------------------------------------------------------------------------*/
volatile bool gADC_SingleEndOfConversion;
vu32 gPotentiometerLevel;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
  RETARGET_Configuration();

  ADC_Configuration();

  /* Enable ADC                                                                                             */
  ADC_Cmd(HT_ADC0, ENABLE);

  /* Software trigger to start ADC conversion                                                               */
  ADC_SoftwareStartConvCmd(HT_ADC0, ENABLE);

  while (1)
  {
    if (gADC_SingleEndOfConversion)
    {
      printf("\rPotentiometer level is %04d", (int)gPotentiometerLevel);
    }
  }
}

/*********************************************************************************************************//**
  * @brief  ADC Configuration.
  * @retval None
  ***********************************************************************************************************/
void ADC_Configuration(void)
{
  { /* Enable peripheral clock                                                                              */
    CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
    CKCUClock.Bit.AFIO = 1;
    CKCUClock.Bit.ADC0 = 1;
    CKCU_PeripClockConfig(CKCUClock, ENABLE);
  }

  /* Configure AFIO mode as ADC function                                                                    */
  AFIO_GPxConfig(HTCFG_VR_GPIO_ID, HTCFG_VR_AFIO_PIN, AFIO_FUN_ADC0);

  { /* ADC related settings                                                                                 */
    /* CK_ADC frequency is set to (CK_AHB / HTCFG_ADC_PRESCALER)                                            */
    CKCU_SetADCnPrescaler(CKCU_ADCPRE_ADC0, HTCFG_ADC_PRESCALER);

    /* Continuous mode, sequence length = 1                                                                 */
    ADC_RegularGroupConfig(HT_ADC0, CONTINUOUS_MODE, 1, 0);

    /* ADC conversion time = (Sampling time + Latency) / CK_ADC = (1.5 + ADST + 12.5) / CK_ADC              */
    /* Set ADST = 0, sampling time = 1.5 + ADST                                                             */

    /* Set ADC conversion sequence as channel n                                                             */
    ADC_RegularChannelConfig(HT_ADC0, HTCFG_VR_ADC_CH, 0, 0);

    /* Set software trigger as ADC trigger source                                                           */
    ADC_RegularTrigConfig(HT_ADC0, ADC_TRIG_SOFTWARE);
  }

  /* Enable ADC single end of conversion interrupt                                                          */
  ADC_IntConfig(HT_ADC0, ADC_INT_SINGLE_EOC, ENABLE);

  /* Enable the ADC interrupts                                                                              */
  NVIC_EnableIRQ(ADC0_IRQn);
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
