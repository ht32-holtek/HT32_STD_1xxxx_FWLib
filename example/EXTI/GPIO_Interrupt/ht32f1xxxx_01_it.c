/*********************************************************************************************************//**
 * @file    EXTI/GPIO_Interrupt/ht32f1xxxx_01_it.c
 * @version $Rev:: 5068         $
 * @date    $Date:: 2020-11-07 #$
 * @brief   This file provides all interrupt service routine.
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

/** @addtogroup EXTI_Examples EXTI
  * @{
  */

/** @addtogroup GPIO_Interrupt
  * @{
  */


/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
 * @brief   This function handles NMI exception.
 * @retval  None
 ************************************************************************************************************/
void NMI_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Hard Fault exception.
 * @retval  None
 ************************************************************************************************************/
void HardFault_Handler(void)
{
  #if 1

  static vu32 gIsContinue = 0;
  /*--------------------------------------------------------------------------------------------------------*/
  /* For development FW, MCU run into the while loop when the hardfault occurred.                           */
  /* 1. Stack Checking                                                                                      */
  /*    When a hard fault exception occurs, MCU push following register into the stack (main or process     */
  /*    stack). Confirm R13(SP) value in the Register Window and typing it to the Memory Windows, you can   */
  /*    check following register, especially the PC value (indicate the last instruction before hard fault).*/
  /*    SP + 0x00    0x04    0x08    0x0C    0x10    0x14    0x18    0x1C                                   */
  /*           R0      R1      R2      R3     R12      LR      PC    xPSR                                   */
  while (gIsContinue == 0)
  {
  }
  /* 2. Step Out to Find the Clue                                                                           */
  /*    Change the variable "gIsContinue" to any other value than zero in a Local or Watch Window, then     */
  /*    step out the HardFault_Handler to reach the first instruction after the instruction which caused    */
  /*    the hard fault.                                                                                     */
  /*--------------------------------------------------------------------------------------------------------*/

  #else

  /*--------------------------------------------------------------------------------------------------------*/
  /* For production FW, you shall consider to reboot the system when hardfault occurred.                    */
  /*--------------------------------------------------------------------------------------------------------*/
  NVIC_SystemReset();

  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles Memory Manage exception.
 * @retval  None
 ************************************************************************************************************/
void MemManage_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles Bus Fault exception.
 * @retval  None
 ************************************************************************************************************/
void BusFault_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles Usage Fault exception.
 * @retval  None
 ************************************************************************************************************/
void UsageFault_Handler(void)
{
  while (1);
}

/*********************************************************************************************************//**
 * @brief   This function handles SVCall exception.
 * @retval  None
 ************************************************************************************************************/
void SVC_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles Debug Monitor exception.
 * @retval  None
 ************************************************************************************************************/
void DebugMon_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles PendSVC exception.
 * @retval  None
 ************************************************************************************************************/
void PendSV_Handler(void)
{
}

/*********************************************************************************************************//**
 * @brief   This function handles SysTick Handler.
 * @retval  None
 ************************************************************************************************************/
void SysTick_Handler(void)
{
}

extern vu32 guKeyState[3];

/*********************************************************************************************************//**
 * @brief   This function handles WAKEUP button interrupt.
 * @retval  None
 ************************************************************************************************************/
__STATIC_INLINE void WAKEUP_Button_Process(void)
{
  #if 1
  if (EXTI_GetEdgeFlag(HTCFG_WAKE_EXTI_CH))
  {
    EXTI_ClearEdgeFlag(HTCFG_WAKE_EXTI_CH);
    guKeyState[0] = TRUE;
  }
  #else
  if (EXTI_GetEdgeStatus(HTCFG_WAKE_EXTI_CH, EXTI_EDGE_NEGATIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_WAKE_EXTI_CH);
  }
  else if (EXTI_GetEdgeStatus(HTCFG_WAKE_EXTI_CH, EXTI_EDGE_POSITIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_WAKE_EXTI_CH);
    guKeyState[0] = TRUE;
  }
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles KEY1 button interrupt.
 * @retval  None
 ************************************************************************************************************/
__STATIC_INLINE void KEY1_Button_Process(void)
{
  #if 1
  if (EXTI_GetEdgeFlag(HTCFG_KEY1_EXTI_CH))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY1_EXTI_CH);
    guKeyState[1] = TRUE;
  }
  #else
  if (EXTI_GetEdgeStatus(HTCFG_KEY1_EXTI_CH, EXTI_EDGE_NEGATIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY1_EXTI_CH);
    guKeyState[1] = TRUE;
  }
  else if (EXTI_GetEdgeStatus(HTCFG_KEY1_EXTI_CH, EXTI_EDGE_POSITIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY1_EXTI_CH);
  }
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles KEY2 button interrupt.
 * @retval  None
 ************************************************************************************************************/
__STATIC_INLINE void KEY2_Button_Process(void)
{
  #if 1
  if (EXTI_GetEdgeFlag(HTCFG_KEY2_EXTI_CH))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY2_EXTI_CH);
    guKeyState[2] = TRUE;
  }
  #else
  if (EXTI_GetEdgeStatus(HTCFG_KEY2_EXTI_CH, EXTI_EDGE_NEGATIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY2_EXTI_CH);
    guKeyState[2] = TRUE;
  }
  else if (EXTI_GetEdgeStatus(HTCFG_KEY2_EXTI_CH, EXTI_EDGE_POSITIVE))
  {
    EXTI_ClearEdgeFlag(HTCFG_KEY2_EXTI_CH);
  }
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI1_IRQHandler(void)
{
  #if defined(USE_HT32F1654_DVB)
  KEY1_Button_Process();
  #endif

  #if defined(USE_HT32F1656_DVB)
  KEY1_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI2_IRQHandler(void)
{
  #if defined(USE_HT32F1656_DVB)
  KEY2_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI4_IRQHandler(void)
{
  #if defined(USE_HT32F12345_SK)
  KEY1_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI5_IRQHandler(void)
{
  #if defined(USE_HT32F12345_SK)
  KEY2_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI6_IRQHandler(void)
{
  #if defined(USE_HT32F12364_SK)
  KEY2_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI9_IRQHandler(void)
{
  #if defined(USE_HT32F1654_DVB)
  KEY2_Button_Process();
  #endif

  #if defined(USE_HT32F12364_SK)
  KEY1_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI13_IRQHandler(void)
{
  #if defined(USE_HT32F12366_SK)
  KEY1_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI14_IRQHandler(void)
{
  #if defined(USE_HT32F12366_SK)
  KEY2_Button_Process();
  #endif
}

/*********************************************************************************************************//**
 * @brief   This function handles EXTI interrupt.
 * @retval  None
 ************************************************************************************************************/
void EXTI15_IRQHandler(void)
{
  WAKEUP_Button_Process(); // Fixed in C15
}


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
