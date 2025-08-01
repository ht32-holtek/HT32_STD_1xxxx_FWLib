/*********************************************************************************************************//**
 * @file    ADC/Discontinuous_EXTITrigger/ht32_board_config.h
 * @version $Rev:: 2073         $
 * @date    $Date:: 2020-03-02 #$
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
  #define  HTCFG_VR_ADC_CH                        (ADC_CH_8)

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define  HTCFG_AD2_ADC_CH                       (ADC_CH_0)

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define  HTCFG_AD3_ADC_CH                       (ADC_CH_1)

  #define _HTCFG_KEY1_GPIOX                       A
  #define _HTCFG_KEY1_GPION                       9
#endif

#if defined(USE_HT32F1656_DVB)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV6)

  #define _HTCFG_VR_GPIOX                         C
  #define _HTCFG_VR_GPION                         11
  #define  HTCFG_VR_ADC_CH                        (ADC_CH_15)

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define  HTCFG_AD2_ADC_CH                       (ADC_CH_0)

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define  HTCFG_AD3_ADC_CH                       (ADC_CH_1)

  #define _HTCFG_KEY1_GPIOX                       E
  #define _HTCFG_KEY1_GPION                       1
#endif

#if defined(USE_HT32F12345_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         6
  #define  HTCFG_VR_ADC_CH                        (ADC_CH_6)

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define  HTCFG_AD2_ADC_CH                       (ADC_CH_0)

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define  HTCFG_AD3_ADC_CH                       (ADC_CH_1)

  #define _HTCFG_KEY1_GPIOX                       C
  #define _HTCFG_KEY1_GPION                       4
#endif

#if defined(USE_HT32F12366_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         E
  #define _HTCFG_VR_GPION                         12
  #define  HTCFG_VR_ADC_CH                        (ADC_CH_12)

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define  HTCFG_AD2_ADC_CH                       (ADC_CH_0)

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define  HTCFG_AD3_ADC_CH                       (ADC_CH_1)

  #define _HTCFG_KEY1_GPIOX                       D
  #define _HTCFG_KEY1_GPION                       13
#endif

#if defined(USE_HT32F12364_SK)
  #define HTCFG_ADC_PRESCALER                     (CKCU_ADCPRE_DIV5)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         7
  #define  HTCFG_VR_ADC_CH                        (ADC_CH_7)

  #define _HTCFG_AD2_GPIOX                        A
  #define _HTCFG_AD2_GPION                        0
  #define  HTCFG_AD2_ADC_CH                       (ADC_CH_0)

  #define _HTCFG_AD3_GPIOX                        A
  #define _HTCFG_AD3_GPION                        1
  #define  HTCFG_AD3_ADC_CH                       (ADC_CH_1)

  #define _HTCFG_KEY1_GPIOX                       A
  #define _HTCFG_KEY1_GPION                       9

#endif

#define HTCFG_VR_GPIO_ID                          STRCAT2(GPIO_P,         _HTCFG_VR_GPIOX)
#define HTCFG_VR_AFIO_PIN                         STRCAT2(AFIO_PIN_,      _HTCFG_VR_GPION)

#define HTCFG_AD2_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_AD2_GPIOX)
#define HTCFG_AD2_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_AD2_GPION)

#define HTCFG_AD3_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_AD3_GPIOX)
#define HTCFG_AD3_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_AD3_GPION)

#define HTCFG_ADC_TRIG_EXTI                       STRCAT2(ADC_TRIG_EXTI_, _HTCFG_KEY1_GPION)

#define HTCFG_KEY1_GPIO_CK                        STRCAT2(P,              _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_KEY1_GPION)


#ifdef __cplusplus
}
#endif

#endif
