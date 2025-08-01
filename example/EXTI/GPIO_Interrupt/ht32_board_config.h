/*********************************************************************************************************//**
 * @file    EXTI/GPIO_Interrupt/ht32_board_config.h
 * @version $Rev:: 4198         $
 * @date    $Date:: 2019-08-20 #$
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
  #define _HTCFG_WAKE_GPIOX                       C
  #define _HTCFG_WAKE_GPION                       15
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI15_IRQn

  #define _HTCFG_KEY1_GPIOX                       D
  #define _HTCFG_KEY1_GPION                       1
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI1_IRQn

  #define _HTCFG_KEY2_GPIOX                       B
  #define _HTCFG_KEY2_GPION                       9
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI9_IRQn
#endif

#if defined(USE_HT32F1656_DVB)
  #define _HTCFG_WAKE_GPIOX                       C
  #define _HTCFG_WAKE_GPION                       15
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI15_IRQn

  #define _HTCFG_KEY1_GPIOX                       E
  #define _HTCFG_KEY1_GPION                       1
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI1_IRQn

  #define _HTCFG_KEY2_GPIOX                       E
  #define _HTCFG_KEY2_GPION                       2
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI2_IRQn
#endif

#if defined(USE_HT32F12345_SK)
  #define _HTCFG_WAKE_GPIOX                       C
  #define _HTCFG_WAKE_GPION                       15
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI15_IRQn

  #define _HTCFG_KEY1_GPIOX                       C
  #define _HTCFG_KEY1_GPION                       4
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI4_IRQn

  #define _HTCFG_KEY2_GPIOX                       C
  #define _HTCFG_KEY2_GPION                       5
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI5_IRQn
#endif

#if defined(USE_HT32F12366_SK)
  #define _HTCFG_WAKE_GPIOX                       C
  #define _HTCFG_WAKE_GPION                       15
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI15_IRQn

  #define _HTCFG_KEY1_GPIOX                       D
  #define _HTCFG_KEY1_GPION                       13
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI13_IRQn

  #define _HTCFG_KEY2_GPIOX                       D
  #define _HTCFG_KEY2_GPION                       14
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI14_IRQn
#endif

#if defined(USE_HT32F12364_SK)
  #define _HTCFG_WAKE_GPIOX                       C
  #define _HTCFG_WAKE_GPION                       15
  #define  HTCFG_WAKE_EXTI_IRQn                   EXTI15_IRQn

  #define _HTCFG_KEY1_GPIOX                       A
  #define _HTCFG_KEY1_GPION                       9
  #define  HTCFG_KEY1_EXTI_IRQn                   EXTI9_IRQn

  #define _HTCFG_KEY2_GPIOX                       C
  #define _HTCFG_KEY2_GPION                       6
  #define  HTCFG_KEY2_EXTI_IRQn                   EXTI6_IRQn
#endif

#define HTCFG_WAKE_GPIO_CK                        STRCAT2(P,              _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_WAKE_GPION)
#define HTCFG_WAKE_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_WAKE_GPIOX)
#define HTCFG_WAKE_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_WAKE_GPION)

#define HTCFG_KEY1_GPIO_CK                        STRCAT2(P,              _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_KEY1_GPION)
#define HTCFG_KEY1_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_KEY1_GPIOX)
#define HTCFG_KEY1_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_KEY1_GPION)

#define HTCFG_KEY2_GPIO_CK                        STRCAT2(P,              _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_GPIO_ID                        STRCAT2(GPIO_P,         _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_AFIO_PIN                       STRCAT2(AFIO_PIN_,      _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_GPIO_PORT                      STRCAT2(HT_GPIO,        _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_GPIO_PIN                       STRCAT2(GPIO_PIN_,      _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_AFIO_EXTI_CH                   STRCAT2(AFIO_EXTI_CH_,  _HTCFG_KEY2_GPION)
#define HTCFG_KEY2_AFIO_ESS                       STRCAT2(AFIO_ESS_P,     _HTCFG_KEY2_GPIOX)
#define HTCFG_KEY2_EXTI_CH                        STRCAT2(EXTI_CHANNEL_,  _HTCFG_KEY2_GPION)


#ifdef __cplusplus
}
#endif

#endif
