/*********************************************************************************************************//**
 * @file    USBD/USB_Video/ht32_board_config.h
 * @version $Rev:: 1709         $
 * @date    $Date:: 2019-06-18 #$
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
  #define HTCFG_USBPRE_DIV                              (CKCU_USBPRE_DIV3)
#endif

#if defined(USE_HT32F1655_56)
  #define HTCFG_USBPRE_DIV                              (CKCU_USBPRE_DIV3)
#endif

#if defined(USE_HT32F12345)
  #define HTCFG_USBPRE_DIV                              (CKCU_USBPRE_DIV2)
#endif

#if defined(USE_HT32F12365_66)
  #define HTCFG_USBPRE_DIV                              (CKCU_USBPRE_DIV2)
#endif

#if defined(USE_HT32F12364)
#endif

#ifdef __cplusplus
}
#endif

#endif
