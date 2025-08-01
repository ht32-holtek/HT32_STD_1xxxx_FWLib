/*********************************************************************************************************//**
 * @file    USART/PDMA/ht32_board_config.h
 * @version $Rev:: 2003         $
 * @date    $Date:: 2020-01-22 #$
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
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    2
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    3
  #define HTCFG_UART_IPN                          USART0

  #define HTCFG_TX_PDMA_CH                        (PDMA_USART0_TX)
  #define HTCFG_RX_PDMA_CH                        (PDMA_USART0_RX)
  #define HTCFG_TX_PDMA_IRQ                       (PDMACH3_IRQn)
  #define HTCFG_RX_PDMA_IRQ                       (PDMACH2_IRQn)
  #define HTCFG_TX_PDMA_IRQHandler                (PDMA_CH3_IRQHandler)
  #define HTCFG_RX_PDMA_IRQHandler                (PDMA_CH2_IRQHandler)
  #define HTCFG_PDMA_CURRENT_TRANSFER_SIZE        (HT_PDMA->PDMACH2.CTSR >> 16)
#endif

#if defined(USE_HT32F1655_56)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    2
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    3
  #define HTCFG_UART_IPN                          USART0

  #define HTCFG_TX_PDMA_CH                        (PDMA_USART0_TX)
  #define HTCFG_RX_PDMA_CH                        (PDMA_USART0_RX)
  #define HTCFG_TX_PDMA_IRQ                       (PDMACH3_IRQn)
  #define HTCFG_RX_PDMA_IRQ                       (PDMACH2_IRQn)
  #define HTCFG_TX_PDMA_IRQHandler                (PDMA_CH3_IRQHandler)
  #define HTCFG_RX_PDMA_IRQHandler                (PDMA_CH2_IRQHandler)
  #define HTCFG_PDMA_CURRENT_TRANSFER_SIZE        (HT_PDMA->PDMACH2.CTSR >> 16)
#endif

#if defined(USE_HT32F12345)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    2
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    3
  #define HTCFG_UART_IPN                          USART0

  #define HTCFG_TX_PDMA_CH                        (PDMA_USART0_TX)
  #define HTCFG_RX_PDMA_CH                        (PDMA_USART0_RX)
  #define HTCFG_TX_PDMA_IRQ                       (PDMACH3_IRQn)
  #define HTCFG_RX_PDMA_IRQ                       (PDMACH2_IRQn)
  #define HTCFG_TX_PDMA_IRQHandler                (PDMA_CH3_IRQHandler)
  #define HTCFG_RX_PDMA_IRQHandler                (PDMA_CH2_IRQHandler)
  #define HTCFG_PDMA_CURRENT_TRANSFER_SIZE        (HT_PDMA->PDMACH2.CTSR >> 16)
#endif

#if defined(USE_HT32F12365_66)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    8
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    10
  #define HTCFG_UART_IPN                          USART0

  #define HTCFG_TX_PDMA_CH                        (PDMA_USART0_TX)
  #define HTCFG_RX_PDMA_CH                        (PDMA_USART0_RX)
  #define HTCFG_TX_PDMA_IRQ                       (PDMACH3_IRQn)
  #define HTCFG_RX_PDMA_IRQ                       (PDMACH2_IRQn)
  #define HTCFG_TX_PDMA_IRQHandler                (PDMA_CH3_IRQHandler)
  #define HTCFG_RX_PDMA_IRQHandler                (PDMA_CH2_IRQHandler)
  #define HTCFG_PDMA_CURRENT_TRANSFER_SIZE        (HT_PDMA->PDMACH2.CTSR >> 16)
#endif

#if defined(USE_HT32F12364)
  #define _HTCFG_UART_TX_GPIOX                    A
  #define _HTCFG_UART_TX_GPION                    2
  #define _HTCFG_UART_RX_GPIOX                    A
  #define _HTCFG_UART_RX_GPION                    3
  #define HTCFG_UART_IPN                          USART0

  #define HTCFG_TX_PDMA_CH                        (PDMA_USART0_TX)
  #define HTCFG_RX_PDMA_CH                        (PDMA_USART0_RX)
  #define HTCFG_TX_PDMA_IRQ                       (PDMACH1_IRQn)
  #define HTCFG_RX_PDMA_IRQ                       (PDMACH0_IRQn)
  #define HTCFG_TX_PDMA_IRQHandler                (PDMA_CH1_IRQHandler)
  #define HTCFG_RX_PDMA_IRQHandler                (PDMA_CH0_IRQHandler)
  #define HTCFG_PDMA_CURRENT_TRANSFER_SIZE        (HT_PDMA->PDMACH0.CTSR >> 16)
#endif

#define HTCFG_UART_TX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_TX_GPIOX)
#define HTCFG_UART_RX_GPIO_ID                     STRCAT2(GPIO_P,         _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_TX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_TX_GPION)
#define HTCFG_UART_RX_AFIO_PIN                    STRCAT2(AFIO_PIN_,      _HTCFG_UART_RX_GPION)
#define HTCFG_UART_PORT                           STRCAT2(HT_,             HTCFG_UART_IPN)
#define HTCFG_UART_IRQn                           STRCAT2(HTCFG_UART_IPN, _IRQn)
#define HTCFG_UART_IRQHandler                     STRCAT2(HTCFG_UART_IPN, _IRQHandler)

#define HTCFG_UART_RX_GPIO_CLK                    STRCAT2(P,              _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PORT                   STRCAT2(HT_GPIO,        _HTCFG_UART_RX_GPIOX)
#define HTCFG_UART_RX_GPIO_PIN                    STRCAT2(GPIO_PIN_,      _HTCFG_UART_RX_GPION)

#ifdef __cplusplus
}
#endif

#endif
