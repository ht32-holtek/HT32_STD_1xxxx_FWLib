/*********************************************************************************************************//**
 * @file    ADC/OneShot_PWMTrigger_with_Delay/ht32_board_config.h
 * @version $Rev:: 2440         $
 * @date    $Date:: 2021-06-10 #$
 * @brief   The header file of board configuration.
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
#ifndef __HT32_BOARD_CONFIG_H
#define __HT32_BOARD_CONFIG_H

#ifdef __cplusplus
 extern "C" {
#endif


/* Settings ------------------------------------------------------------------------------------------------*/
#if defined(USE_HT32F1654_DVB)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV6)

  #define _HTCFG_VR_GPIOX                         C
  #define _HTCFG_VR_GPION                         9
  #define _HTCFG_VR_ADC_CHN                       8

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define _HTCFG_AD2_ADC_CHN                      0

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define _HTCFG_AD3_ADC_CHN                      1

  #define _HTCFG_PWM_GPIOX                        A
  #define _HTCFG_PWM_GPION                        6
  #define  HTCFG_PWM_TM_CH                        (TM_CH_2)
#endif

#if defined(USE_HT32F1656_DVB)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV6)

  #define _HTCFG_VR_GPIOX                         C
  #define _HTCFG_VR_GPION                         11
  #define _HTCFG_VR_ADC_CHN                       15

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define _HTCFG_AD2_ADC_CHN                      0

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define _HTCFG_AD3_ADC_CHN                      1

  #define _HTCFG_PWM_GPIOX                        A
  #define _HTCFG_PWM_GPION                        6
  #define  HTCFG_PWM_TM_CH                        (TM_CH_2)
#endif

#if defined(USE_HT32F12345_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         6
  #define  _HTCFG_VR_ADC_CHN                      6

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define _HTCFG_AD2_ADC_CHN                      0

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define _HTCFG_AD3_ADC_CHN                      1

  #define _HTCFG_PWM_GPIOX                        C
  #define _HTCFG_PWM_GPION                        11
  #define  HTCFG_PWM_TM_CH                        (TM_CH_2)
#endif

#if defined(USE_HT32F12366_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         E
  #define _HTCFG_VR_GPION                         12
  #define _HTCFG_VR_ADC_CHN                       12

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define _HTCFG_AD2_ADC_CHN                      0

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define _HTCFG_AD3_ADC_CHN                      1

  #define _HTCFG_PWM_GPIOX                        C
  #define _HTCFG_PWM_GPION                        11
  #define  HTCFG_PWM_TM_CH                        (TM_CH_2)
#endif

#if defined(USE_HT32F12364_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         7
  #define _HTCFG_VR_ADC_CHN                       7

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define _HTCFG_AD2_ADC_CHN                      0

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define _HTCFG_AD3_ADC_CHN                      1

  #define _HTCFG_PWM_GPIOX                        A
  #define _HTCFG_PWM_GPION                        6
  #define  HTCFG_PWM_TM_CH                        (TM_CH_2)
#endif

#define HTCFG_VR_GPIO_ID                          STRCAT2(GPIO_P,         _HTCFG_VR_GPIOX)
#define HTCFG_VR_AFIO_PIN                         STRCAT2(AFIO_PIN_,      _HTCFG_VR_GPION)
#define HTCFG_VR_ADC_CH                           STRCAT2(ADC_CH_,        _HTCFG_VR_ADC_CHN)

#define HTCFG_AD2_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_AD2_GPIOX)
#define HTCFG_AD2_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_AD2_GPION)
#define HTCFG_AD2_ADC_CH                          STRCAT2(ADC_CH_,        _HTCFG_AD2_ADC_CHN)

#define HTCFG_AD3_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_AD3_GPIOX)
#define HTCFG_AD3_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_AD3_GPION)
#define HTCFG_AD3_ADC_CH                          STRCAT2(ADC_CH_,        _HTCFG_AD3_ADC_CHN)

#define HTCFG_PWM_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_PWM_GPIOX)
#define HTCFG_PWM_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_PWM_GPION)


#ifdef __cplusplus
}
#endif

#endif
