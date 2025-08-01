/*********************************************************************************************************//**
 * @file    I2S/CodecLoopback_PDMA/ht32_board_config.h
 * @version $Rev:: 2136         $
 * @date    $Date:: 2020-07-17 #$
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
#if (LIBCFG_NO_I2S)
  #error "This example code does not apply to the chip you selected."
#endif

#if defined(USE_HT32F1653_54)
  #define HTCFG_I2C_IPN                           I2C1
  #define HTCFG_I2C_SDA_GPIOX                     A
  #define HTCFG_I2C_SDA_GPION                     1
  #define HTCFG_I2C_SCL_GPIOX                     A
  #define HTCFG_I2C_SCL_GPION                     0

  #define HTCFG_I2S_SDO_GPIOX                     B
  #define HTCFG_I2S_SDO_GPION                     10
  #define HTCFG_I2S_SDI_GPIOX                     B
  #define HTCFG_I2S_SDI_GPION                     11
  #define HTCFG_I2S_MCLK_GPIOX                    A
  #define HTCFG_I2S_MCLK_GPION                    7
  #define HTCFG_I2S_BCLK_GPIOX                    C
  #define HTCFG_I2S_BCLK_GPION                    1
  #define HTCFG_I2S_WS_GPIOX                      C
  #define HTCFG_I2S_WS_GPION                      0

  #define HTCFG_I2S_VOICE_X_DIV                   (12)
  #define HTCFG_I2S_VOICE_Y_DIV                   (211)

  #define HTCFG_I2S_MUSIC_X_DIV                   (86)
  #define HTCFG_I2S_MUSIC_Y_DIV                   (252)
#endif

#if defined(USE_HT32F1655_56)
  #define HTCFG_I2C_IPN                           I2C0
  #define HTCFG_I2C_SDA_GPIOX                     B
  #define HTCFG_I2C_SDA_GPION                     13
  #define HTCFG_I2C_SCL_GPIOX                     B
  #define HTCFG_I2C_SCL_GPION                     12

  #define HTCFG_I2S_SDO_GPIOX                     D
  #define HTCFG_I2S_SDO_GPION                     2
  #define HTCFG_I2S_SDI_GPIOX                     D
  #define HTCFG_I2S_SDI_GPION                     3
  #define HTCFG_I2S_MCLK_GPIOX                    D
  #define HTCFG_I2S_MCLK_GPION                    4
  #define HTCFG_I2S_BCLK_GPIOX                    D
  #define HTCFG_I2S_BCLK_GPION                    1
  #define HTCFG_I2S_WS_GPIOX                      E
  #define HTCFG_I2S_WS_GPION                      14

  #define HTCFG_I2S_VOICE_X_DIV                   (12)
  #define HTCFG_I2S_VOICE_Y_DIV                   (211)

  #define HTCFG_I2S_MUSIC_X_DIV                   (86)
  #define HTCFG_I2S_MUSIC_Y_DIV                   (252)
#endif

#if defined(USE_HT32F12345)
  #define HTCFG_I2C_IPN                           I2C1
  #define HTCFG_I2C_SDA_GPIOX                     A
  #define HTCFG_I2C_SDA_GPION                     1
  #define HTCFG_I2C_SCL_GPIOX                     A
  #define HTCFG_I2C_SCL_GPION                     0

  #define HTCFG_I2S_SDO_GPIOX                     C
  #define HTCFG_I2S_SDO_GPION                     2
  #define HTCFG_I2S_SDI_GPIOX                     C
  #define HTCFG_I2S_SDI_GPION                     3
  #define HTCFG_I2S_MCLK_GPIOX                    A
  #define HTCFG_I2S_MCLK_GPION                    8
  #define HTCFG_I2S_BCLK_GPIOX                    C
  #define HTCFG_I2S_BCLK_GPION                    1
  #define HTCFG_I2S_WS_GPIOX                      C
  #define HTCFG_I2S_WS_GPION                      0

  #define HTCFG_I2S_VOICE_X_DIV                   (10)
  #define HTCFG_I2S_VOICE_Y_DIV                   (234)

  #define HTCFG_I2S_MUSIC_X_DIV                   (32)
  #define HTCFG_I2S_MUSIC_Y_DIV                   (125)
#endif

#if defined(USE_HT32F12365_66)
  #define HTCFG_I2C_IPN                           I2C0
  #define HTCFG_I2C_SDA_GPIOX                     B
  #define HTCFG_I2C_SDA_GPION                     13
  #define HTCFG_I2C_SCL_GPIOX                     B
  #define HTCFG_I2C_SCL_GPION                     12

  #define HTCFG_I2S_SDO_GPIOX                     D
  #define HTCFG_I2S_SDO_GPION                     2
  #define HTCFG_I2S_SDI_GPIOX                     D
  #define HTCFG_I2S_SDI_GPION                     3
  #define HTCFG_I2S_MCLK_GPIOX                    A
  #define HTCFG_I2S_MCLK_GPION                    11
  #define HTCFG_I2S_BCLK_GPIOX                    D
  #define HTCFG_I2S_BCLK_GPION                    1
  #define HTCFG_I2S_WS_GPIOX                      E
  #define HTCFG_I2S_WS_GPION                      14

  #define HTCFG_I2S_VOICE_X_DIV                   (10)
  #define HTCFG_I2S_VOICE_Y_DIV                   (234)

  #define HTCFG_I2S_MUSIC_X_DIV                   (32)
  #define HTCFG_I2S_MUSIC_Y_DIV                   (125)
#endif

#define HTCFG_I2C_PORT                            STRCAT2(HT_, HTCFG_I2C_IPN)
#define HTCFG_I2C_IRQn                            STRCAT2(HTCFG_I2C_IPN, _IRQn)
#define HTCFG_I2C_IRQHandler                      STRCAT2(HTCFG_I2C_IPN, _IRQHandler)

#define HTCFG_I2C_SDA_GPIO_ID                     STRCAT2(GPIO_P,    HTCFG_I2C_SDA_GPIOX)
#define HTCFG_I2C_SDA_AFIO_PIN                    STRCAT2(AFIO_PIN_, HTCFG_I2C_SDA_GPION)
#define HTCFG_I2C_SCL_GPIO_ID                     STRCAT2(GPIO_P,    HTCFG_I2C_SCL_GPIOX)
#define HTCFG_I2C_SCL_AFIO_PIN                    STRCAT2(AFIO_PIN_, HTCFG_I2C_SCL_GPION)

#define HTCFG_I2S_SDO_GPIO_ID                     STRCAT2(GPIO_P,    HTCFG_I2S_SDO_GPIOX)
#define HTCFG_I2S_SDO_AFIO_PIN                    STRCAT2(AFIO_PIN_, HTCFG_I2S_SDO_GPION)
#define HTCFG_I2S_SDI_GPIO_ID                     STRCAT2(GPIO_P,    HTCFG_I2S_SDI_GPIOX)
#define HTCFG_I2S_SDI_AFIO_PIN                    STRCAT2(AFIO_PIN_, HTCFG_I2S_SDI_GPION)
#define HTCFG_I2S_MCLK_GPIO_ID                    STRCAT2(GPIO_P,    HTCFG_I2S_MCLK_GPIOX)
#define HTCFG_I2S_MCLK_AFIO_PIN                   STRCAT2(AFIO_PIN_, HTCFG_I2S_MCLK_GPION)
#define HTCFG_I2S_BCLK_GPIO_ID                    STRCAT2(GPIO_P,    HTCFG_I2S_BCLK_GPIOX)
#define HTCFG_I2S_BCLK_AFIO_PIN                   STRCAT2(AFIO_PIN_, HTCFG_I2S_BCLK_GPION)
#define HTCFG_I2S_WS_GPIO_ID                      STRCAT2(GPIO_P,    HTCFG_I2S_WS_GPIOX)
#define HTCFG_I2S_WS_AFIO_PIN                     STRCAT2(AFIO_PIN_, HTCFG_I2S_WS_GPION)

#ifdef __cplusplus
}
#endif

#endif
