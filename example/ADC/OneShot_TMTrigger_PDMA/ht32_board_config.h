/*********************************************************************************************************//**
 * @file    ADC/OneShot_TMTrigger_PDMA/ht32_board_config.h
 * @version $Rev:: 2326         $
 * @date    $Date:: 2021-02-04 #$
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
  #define  HTCFG_ADC_PRESCALER                    (CKCU_ADCPRE_DIV6)

  #define _HTCFG_VR_GPIOX                         C
  #define _HTCFG_VR_GPION                         9
  #define _HTCFG_VR_ADC_CHN                       8

  #define _HTCFG_LED_GPIOX                        B
  #define _HTCFG_LED_GPION                        6
  #define  HTCFG_LED_TM_IPN                       MCTM1
  #define  HTCFG_LED_TM_CHN                       0
#endif

#if defined(USE_HT32F1656_DVB)
  #define  HTCFG_ADC_PRESCALER                    (CKCU_ADCPRE_DIV6)

  #define _HTCFG_VR_GPIOX                         C
  #define _HTCFG_VR_GPION                         11
  #define _HTCFG_VR_ADC_CHN                       15

  #define _HTCFG_LED_GPIOX                        A
  #define _HTCFG_LED_GPION                        10
  #define  HTCFG_LED_TM_IPN                       MCTM1
  #define  HTCFG_LED_TM_CHN                       1
#endif

#if defined(USE_HT32F12345_SK)
  #define  HTCFG_ADC_PRESCALER                    (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         6
  #define _HTCFG_VR_ADC_CHN                       6

  #define _HTCFG_LED_GPIOX                        B
  #define _HTCFG_LED_GPION                        6
  #define  HTCFG_LED_TM_IPN                       MCTM1
  #define  HTCFG_LED_TM_CHN                       0
#endif

#if defined(USE_HT32F12366_SK)
  #define  HTCFG_ADC_PRESCALER                    (CKCU_ADCPRE_DIV8)

  #define _HTCFG_VR_GPIOX                         E
  #define _HTCFG_VR_GPION                         12
  #define _HTCFG_VR_ADC_CHN                       12

  #define _HTCFG_LED_GPIOX                        E
  #define _HTCFG_LED_GPION                        2
  #define  HTCFG_LED_TM_IPN                       MCTM1
  #define  HTCFG_LED_TM_CHN                       0
  #define  HTCFG_LED_MCTM_CHNO                    1
#endif

#if defined(USE_HT32F12364_SK)
  #define  HTCFG_ADC_PRESCALER                    (CKCU_ADCPRE_DIV5)

  #define _HTCFG_VR_GPIOX                         A
  #define _HTCFG_VR_GPION                         7
  #define _HTCFG_VR_ADC_CHN                       7

  #define _HTCFG_LED_GPIOX                        C
  #define _HTCFG_LED_GPION                        11
  #define  HTCFG_LED_TM_IPN                       GPTM0
  #define  HTCFG_LED_TM_CHN                       2
#endif

#define HTCFG_VR_GPIO_ID                          STRCAT2(GPIO_P,         _HTCFG_VR_GPIOX)
#define HTCFG_VR_AFIO_PIN                         STRCAT2(AFIO_PIN_,      _HTCFG_VR_GPION)
#define HTCFG_VR_ADC_CH                           STRCAT2(ADC_CH_,        _HTCFG_VR_ADC_CHN)

#define HTCFG_LED_GPIO_ID                         STRCAT2(GPIO_P,         _HTCFG_LED_GPIOX)
#define HTCFG_LED_AFIO_PIN                        STRCAT2(AFIO_PIN_,      _HTCFG_LED_GPION)
#define HTCFG_LED_AFIO_FUN                        STRCAT2(AFIO_FUN_,       HTCFG_LED_TM_IPN)
#define HTCFG_LED_TM_PORT                         STRCAT2(HT_,             HTCFG_LED_TM_IPN)
#define HTCFG_LED_TM_CH                           STRCAT2(TM_CH_,          HTCFG_LED_TM_CHN)
#define HTCFG_ADC_TRIG_TM                         STRCAT3(ADC_TRIG_,       HTCFG_LED_TM_IPN, _MTO)


#ifdef __cplusplus
}
#endif

#endif
