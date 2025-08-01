/*********************************************************************************************************//**
 * @file    TM/PWMInput/ht32_board_config.h
 * @version $Rev:: 1723         $
 * @date    $Date:: 2019-06-24 #$
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
#define HTCFG_INPUT_PWM_TM_CLK(CK)                (CK.Bit.GPTM1)
#define HTCFG_INPUT_PWM_TM                        (HT_GPTM1)
#define HTCFG_INPUT_PWM_TM_GPIO_ID                (GPIO_PC)
#define HTCFG_INPUT_PWM_TM_GPIO                   (HT_GPIOC)
#define HTCFG_INPUT_PWM_TM_GPIO_PIN               (GPIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_PIN               (AFIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_FUN               (AFIO_FUN_MCTM_GPTM)
#define HTCFG_INPUT_PWM_TM_GPIO_CLK(CK)           (CK.Bit.PC)
#define HTCFG_INPUT_PWM_TM_CHANNEL                (TM_CH_1)
#define HTCFG_INPUT_PWM_IRQ                       (GPTM1_IRQn)
#define HTCFG_INPUT_PWM_INT_CHX                   (TM_INT_CH1CC)
#define HTCFG_INPUT_PWM_IRQHandler                GPTM1_IRQHandler

#define HTCFG_OUTPUT_PWM_TM_CLK(CK)               (CK.Bit.GPTM0)
#define HTCFG_OUTPUT_PWM_TM                       (HT_GPTM0)
#define HTCFG_OUTPUT_PWM_TM_CHANNEL               (TM_CH_1)
#define HTCFG_OUTPUT_PWM_TM_GPIO_ID               (GPIO_PA)
#define HTCFG_OUTPUT_PWM_TM_AFIO_PIN              (AFIO_PIN_5)
#define HTCFG_OUTPUT_PWM_TM_AFIO_FUN              (AFIO_FUN_MCTM_GPTM)
#endif

#if defined(USE_HT32F1655_56)
#define HTCFG_INPUT_PWM_TM_CLK(CK)                (CK.Bit.GPTM1)
#define HTCFG_INPUT_PWM_TM                        (HT_GPTM1)
#define HTCFG_INPUT_PWM_TM_GPIO_ID                (GPIO_PA)
#define HTCFG_INPUT_PWM_TM_GPIO                   (HT_GPIOA)
#define HTCFG_INPUT_PWM_TM_GPIO_PIN               (GPIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_PIN               (AFIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_FUN               (AFIO_FUN_MCTM_GPTM)
#define HTCFG_INPUT_PWM_TM_GPIO_CLK(CK)           (CK.Bit.PA)
#define HTCFG_INPUT_PWM_TM_CHANNEL                (TM_CH_1)
#define HTCFG_INPUT_PWM_IRQ                       (GPTM1_IRQn)
#define HTCFG_INPUT_PWM_INT_CHX                   (TM_INT_CH1CC)
#define HTCFG_INPUT_PWM_IRQHandler                GPTM1_IRQHandler

#define HTCFG_OUTPUT_PWM_TM_CLK(CK)               (CK.Bit.GPTM0)
#define HTCFG_OUTPUT_PWM_TM                       (HT_GPTM0)
#define HTCFG_OUTPUT_PWM_TM_CHANNEL               (TM_CH_1)
#define HTCFG_OUTPUT_PWM_TM_GPIO_ID               (GPIO_PA)
#define HTCFG_OUTPUT_PWM_TM_AFIO_PIN              (AFIO_PIN_5)
#define HTCFG_OUTPUT_PWM_TM_AFIO_FUN              (AFIO_FUN_MCTM_GPTM)
#endif

#if defined(USE_HT32F12345)
#define HTCFG_INPUT_PWM_TM_CLK(CK)                (CK.Bit.GPTM1)
#define HTCFG_INPUT_PWM_TM                        (HT_GPTM1)
#define HTCFG_INPUT_PWM_TM_GPIO_ID                (GPIO_PA)
#define HTCFG_INPUT_PWM_TM_GPIO                   (HT_GPIOA)
#define HTCFG_INPUT_PWM_TM_GPIO_PIN               (GPIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_PIN               (AFIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_FUN               (AFIO_FUN_MCTM_GPTM)
#define HTCFG_INPUT_PWM_TM_GPIO_CLK(CK)           (CK.Bit.PA)
#define HTCFG_INPUT_PWM_TM_CHANNEL                (TM_CH_1)
#define HTCFG_INPUT_PWM_IRQ                       (GPTM1_IRQn)
#define HTCFG_INPUT_PWM_INT_CHX                   (TM_INT_CH1CC)
#define HTCFG_INPUT_PWM_IRQHandler                GPTM1_IRQHandler

#define HTCFG_OUTPUT_PWM_TM_CLK(CK)               (CK.Bit.GPTM0)
#define HTCFG_OUTPUT_PWM_TM                       (HT_GPTM0)
#define HTCFG_OUTPUT_PWM_TM_CHANNEL               (TM_CH_1)
#define HTCFG_OUTPUT_PWM_TM_GPIO_ID               (GPIO_PA)
#define HTCFG_OUTPUT_PWM_TM_AFIO_PIN              (AFIO_PIN_5)
#define HTCFG_OUTPUT_PWM_TM_AFIO_FUN              (AFIO_FUN_MCTM_GPTM)
#endif

#if defined(USE_HT32F12365_66)
#define HTCFG_INPUT_PWM_TM_CLK(CK)                (CK.Bit.GPTM1)
#define HTCFG_INPUT_PWM_TM                        (HT_GPTM1)
#define HTCFG_INPUT_PWM_TM_GPIO_ID                (GPIO_PA)
#define HTCFG_INPUT_PWM_TM_GPIO                   (HT_GPIOA)
#define HTCFG_INPUT_PWM_TM_GPIO_PIN               (GPIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_PIN               (AFIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_FUN               (AFIO_FUN_MCTM_GPTM)
#define HTCFG_INPUT_PWM_TM_GPIO_CLK(CK)           (CK.Bit.PA)
#define HTCFG_INPUT_PWM_TM_CHANNEL                (TM_CH_1)
#define HTCFG_INPUT_PWM_IRQ                       (GPTM1_IRQn)
#define HTCFG_INPUT_PWM_INT_CHX                   (TM_INT_CH1CC)
#define HTCFG_INPUT_PWM_IRQHandler                GPTM1_IRQHandler

#define HTCFG_OUTPUT_PWM_TM_CLK(CK)               (CK.Bit.GPTM0)
#define HTCFG_OUTPUT_PWM_TM                       (HT_GPTM0)
#define HTCFG_OUTPUT_PWM_TM_CHANNEL               (TM_CH_1)
#define HTCFG_OUTPUT_PWM_TM_GPIO_ID               (GPIO_PA)
#define HTCFG_OUTPUT_PWM_TM_AFIO_PIN              (AFIO_PIN_5)
#define HTCFG_OUTPUT_PWM_TM_AFIO_FUN              (AFIO_FUN_MCTM_GPTM)
#endif

#if defined(USE_HT32F12364)
#define HTCFG_INPUT_PWM_TM_CLK(CK)                (CK.Bit.GPTM0)
#define HTCFG_INPUT_PWM_TM                        (HT_GPTM0)
#define HTCFG_INPUT_PWM_TM_GPIO_ID                (GPIO_PA)
#define HTCFG_INPUT_PWM_TM_GPIO                   (HT_GPIOA)
#define HTCFG_INPUT_PWM_TM_GPIO_PIN               (GPIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_PIN               (AFIO_PIN_1)
#define HTCFG_INPUT_PWM_TM_AFIO_FUN               (AFIO_FUN_MCTM_GPTM)
#define HTCFG_INPUT_PWM_TM_GPIO_CLK(CK)           (CK.Bit.PA)
#define HTCFG_INPUT_PWM_TM_CHANNEL                (TM_CH_1)
#define HTCFG_INPUT_PWM_IRQ                       (GPTM0_IRQn)
#define HTCFG_INPUT_PWM_INT_CHX                   (TM_INT_CH1CC)
#define HTCFG_INPUT_PWM_IRQHandler                GPTM0_IRQHandler

#define HTCFG_OUTPUT_PWM_TM_CLK(CK)               (CK.Bit.PWM0)
#define HTCFG_OUTPUT_PWM_TM                       (HT_PWM0)
#define HTCFG_OUTPUT_PWM_TM_CHANNEL               (TM_CH_1)
#define HTCFG_OUTPUT_PWM_TM_GPIO_ID               (GPIO_PA)
#define HTCFG_OUTPUT_PWM_TM_AFIO_PIN              (AFIO_PIN_10)
#define HTCFG_OUTPUT_PWM_TM_AFIO_FUN              (AFIO_FUN_PWM_SCTM)
#endif

#ifdef __cplusplus
}
#endif
#endif
