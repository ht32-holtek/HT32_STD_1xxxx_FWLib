/*********************************************************************************************************//**
 * @file    I2C/PDMA/ht32_board_config.h
 * @version $Rev:: 2792         $
 * @date    $Date:: 2022-11-24 #$
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
#if defined(USE_HT32F1653_54)
  #define HTCFG_I2C_MASTER_PORT            (HT_I2C0)
  #define HTCFG_I2C_MASTER_SCL_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SCL_AFIO_PIN    (AFIO_PIN_4)
  #define HTCFG_I2C_MASTER_SDA_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SDA_AFIO_PIN    (AFIO_PIN_5)

  #define HTCFG_I2C_SLAVE_PORT             (HT_I2C1)
  #define HTCFG_I2C_SLAVE_SCL_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SCL_AFIO_PIN     (AFIO_PIN_0)
  #define HTCFG_I2C_SLAVE_SDA_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SDA_AFIO_PIN     (AFIO_PIN_1)

  #define HTCFG_I2C_MASTER_RX_DMA          (PDMA_I2C0_RX)
  #define HTCFG_I2C_SLAVE_TX_DMA           (PDMA_I2C1_TX)
 #endif

#if defined(USE_HT32F1655_56)
  #define HTCFG_I2C_MASTER_PORT            (HT_I2C0)
  #define HTCFG_I2C_MASTER_SCL_GPIO_ID     (GPIO_PB)
  #define HTCFG_I2C_MASTER_SCL_AFIO_PIN    (AFIO_PIN_12)
  #define HTCFG_I2C_MASTER_SDA_GPIO_ID     (GPIO_PB)
  #define HTCFG_I2C_MASTER_SDA_AFIO_PIN    (AFIO_PIN_13)

  #define HTCFG_I2C_SLAVE_PORT             (HT_I2C1)
  #define HTCFG_I2C_SLAVE_SCL_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SCL_AFIO_PIN     (AFIO_PIN_0)
  #define HTCFG_I2C_SLAVE_SDA_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SDA_AFIO_PIN     (AFIO_PIN_1)

  #define HTCFG_I2C_MASTER_RX_DMA          (PDMA_I2C0_RX)
  #define HTCFG_I2C_SLAVE_TX_DMA           (PDMA_I2C1_TX)
#endif

#if defined(USE_HT32F12345)
  #define HTCFG_I2C_MASTER_PORT            (HT_I2C0)
  #define HTCFG_I2C_MASTER_SCL_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SCL_AFIO_PIN    (AFIO_PIN_4)
  #define HTCFG_I2C_MASTER_SDA_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SDA_AFIO_PIN    (AFIO_PIN_5)

  #define HTCFG_I2C_SLAVE_PORT             (HT_I2C1)
  #define HTCFG_I2C_SLAVE_SCL_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SCL_AFIO_PIN     (AFIO_PIN_0)
  #define HTCFG_I2C_SLAVE_SDA_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SDA_AFIO_PIN     (AFIO_PIN_1)

  #define HTCFG_I2C_MASTER_RX_DMA          (PDMA_I2C0_RX)
  #define HTCFG_I2C_SLAVE_TX_DMA           (PDMA_I2C1_TX)
#endif

#if defined(USE_HT32F12365_66)
  #define HTCFG_I2C_MASTER_PORT            (HT_I2C0)
  #define HTCFG_I2C_MASTER_SCL_GPIO_ID     (GPIO_PB)
  #define HTCFG_I2C_MASTER_SCL_AFIO_PIN    (AFIO_PIN_12)
  #define HTCFG_I2C_MASTER_SDA_GPIO_ID     (GPIO_PB)
  #define HTCFG_I2C_MASTER_SDA_AFIO_PIN    (AFIO_PIN_13)

  #define HTCFG_I2C_SLAVE_PORT             (HT_I2C1)
  #define HTCFG_I2C_SLAVE_SCL_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SCL_AFIO_PIN     (AFIO_PIN_0)
  #define HTCFG_I2C_SLAVE_SDA_GPIO_ID      (GPIO_PA)
  #define HTCFG_I2C_SLAVE_SDA_AFIO_PIN     (AFIO_PIN_1)

  #define HTCFG_I2C_MASTER_RX_DMA          (PDMA_I2C0_RX)
  #define HTCFG_I2C_SLAVE_TX_DMA           (PDMA_I2C1_TX)
#endif

#if defined(USE_HT32F12364)
  #define HTCFG_I2C_MASTER_PORT            (HT_I2C0)
  #define HTCFG_I2C_MASTER_SCL_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SCL_AFIO_PIN    (AFIO_PIN_4)
  #define HTCFG_I2C_MASTER_SDA_GPIO_ID     (GPIO_PA)
  #define HTCFG_I2C_MASTER_SDA_AFIO_PIN    (AFIO_PIN_5)

  #define HTCFG_I2C_SLAVE_PORT             (HT_I2C1)
  #define HTCFG_I2C_SLAVE_SCL_GPIO_ID      (GPIO_PD)
  #define HTCFG_I2C_SLAVE_SCL_AFIO_PIN     (AFIO_PIN_1)
  #define HTCFG_I2C_SLAVE_SDA_GPIO_ID      (GPIO_PD)
  #define HTCFG_I2C_SLAVE_SDA_AFIO_PIN     (AFIO_PIN_2)

  #define HTCFG_I2C_MASTER_RX_DMA          (PDMA_I2C0_RX)
  #define HTCFG_I2C_SLAVE_TX_DMA           (PDMA_I2C1_TX)
#endif

#ifdef __cplusplus
}
#endif

#endif
