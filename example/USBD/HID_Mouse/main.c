/*********************************************************************************************************//**
 * @file    USBD/HID_Mouse/main.c
 * @version $Rev:: 2986         $
 * @date    $Date:: 2023-12-19 #$
 * @brief   The main program of USB Device HID Mouse example.
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
// <<< Use Configuration Wizard in Context Menu >>>

/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"
#include "ht32_board_config.h"
#include "ht32_usbd_core.h"
#include "ht32_usbd_class.h"
#include "ht32_usbd_descriptor.h"

/** @addtogroup HT32_Series_Peripheral_Examples HT32 Peripheral Examples
  * @{
  */

/** @addtogroup USBD_Examples USBD
  * @{
  */

/** @addtogroup HID_Mouse
  * @{
  */


/* Private function prototypes -----------------------------------------------------------------------------*/
void CKCU_Configuration(void);
void GPIO_Configuration(void);
void USB_Configuration(void);
void USBPLL_Configuration(void);
void Suspend(u32 uPara);

/* Global variables ----------------------------------------------------------------------------------------*/
__ALIGN4 USBDCore_TypeDef gUSBCore;
USBD_Driver_TypeDef gUSBDriver;
u32 gIsLowPowerAllowed = TRUE;

/* Global functions ----------------------------------------------------------------------------------------*/
/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
  CKCU_Configuration();               /* System Related configuration                                       */
  GPIO_Configuration();               /* GPIO Related configuration                                         */
  RETARGET_Configuration();           /* Retarget Related configuration                                     */
  USB_Configuration();                /* USB Related configuration                                          */

  HT32F_DVB_USBConnect();

  while (1)
  {
    USBDCore_MainRoutine(&gUSBCore);  /* USB core main routine                                              */
  }
}

/*********************************************************************************************************//**
  * @brief  Configure the system clocks.
  * @retval None
  ***********************************************************************************************************/
void CKCU_Configuration(void)
{
#if 1
  CKCU_PeripClockConfig_TypeDef CKCUClock = {{ 0 }};
  CKCUClock.Bit.USBD                        = 1;
  CKCUClock.Bit.AFIO                        = 1;
  CKCUClock.Bit.EXTI                        = 1;
#if defined(USE_HT32F1655_56)
  HTCFG_JOYKEY_LEFT_SET_CLOCK(CKCUClock)    = 1;
  HTCFG_JOYKEY_SEL_SET_CLOCK(CKCUClock)     = 1;
  HTCFG_JOYKEY_UP_SET_CLOCK(CKCUClock)      = 1;
  HTCFG_JOYKEY_RIGHT_SET_CLOCK(CKCUClock)   = 1;
  HTCFG_JOYKEY_DOWN_SET_CLOCK(CKCUClock)    = 1;
#endif
  CKCU_PeripClockConfig(CKCUClock, ENABLE);
#endif

  /*--------------------------------------------------------------------------------------------------------*/
  /* Set USB Clock as PLL / HTCFG_USBPRE_DIV                                                                */
  /*--------------------------------------------------------------------------------------------------------*/
  #if defined(HTCFG_USBPRE_DIV)
  CKCU_SetUSBPrescaler(HTCFG_USBPRE_DIV);
  #endif
}

/*********************************************************************************************************//**
  * @brief  Configure the GPIO ports.
  * @retval None
  ***********************************************************************************************************/
void GPIO_Configuration(void)
{
  /*--------------------------------------------------------------------------------------------------------*/
  /* Configure GPIO as input for button                                                                     */
  /*--------------------------------------------------------------------------------------------------------*/
  HT32F_DVB_PBInit(BUTTON_WAKEUP, BUTTON_MODE_GPIO);
  HT32F_DVB_PBInit(BUTTON_KEY1, BUTTON_MODE_GPIO);
  HT32F_DVB_PBInit(BUTTON_KEY2, BUTTON_MODE_GPIO);
  AFIO_EXTISourceConfig((AFIO_EXTI_CH_Enum)KEY1_BUTTON_EXTI_CHANNEL, HTCFG_EXTI_ESS);

#if defined(USE_HT32F1655_56)
  /*--------------------------------------------------------------------------------------------------------*/
  /* Configure GPIO as input for joystick                                                                   */
  /*--------------------------------------------------------------------------------------------------------*/
  GPIO_DirectionConfig(GPIO_PORT[HTCFG_JOYKEY_LEFT_ID], HTCFG_JOYKEY_LEFT_PIN,GPIO_DIR_IN);
  GPIO_InputConfig(GPIO_PORT[HTCFG_JOYKEY_LEFT_ID], HTCFG_JOYKEY_LEFT_PIN,ENABLE);

  GPIO_DirectionConfig(GPIO_PORT[HTCFG_JOYKEY_SEL_ID], HTCFG_JOYKEY_SEL_PIN,GPIO_DIR_IN);
  GPIO_InputConfig(GPIO_PORT[HTCFG_JOYKEY_SEL_ID], HTCFG_JOYKEY_SEL_PIN,ENABLE);

  GPIO_DirectionConfig(GPIO_PORT[HTCFG_JOYKEY_UP_ID], HTCFG_JOYKEY_UP_PIN,GPIO_DIR_IN);
  GPIO_InputConfig(GPIO_PORT[HTCFG_JOYKEY_UP_ID], HTCFG_JOYKEY_UP_PIN,ENABLE);

  GPIO_DirectionConfig(GPIO_PORT[HTCFG_JOYKEY_RIGHT_ID], HTCFG_JOYKEY_RIGHT_PIN,GPIO_DIR_IN);
  GPIO_InputConfig(GPIO_PORT[HTCFG_JOYKEY_RIGHT_ID], HTCFG_JOYKEY_RIGHT_PIN,ENABLE);

  GPIO_DirectionConfig(GPIO_PORT[HTCFG_JOYKEY_DOWN_ID], HTCFG_JOYKEY_DOWN_PIN,GPIO_DIR_IN);
  GPIO_InputConfig(GPIO_PORT[HTCFG_JOYKEY_DOWN_ID], HTCFG_JOYKEY_DOWN_PIN,ENABLE);
#endif
}

/*********************************************************************************************************//**
  * @brief  Configure USB.
  * @retval None
  ***********************************************************************************************************/
void USB_Configuration(void)
{
  #if (LIBCFG_CKCU_USB_PLL)
  USBPLL_Configuration();
  #endif

  gUSBCore.pDriver = (u32 *)&gUSBDriver;                /* Initiate memory pointer of USB driver            */
  gUSBCore.Power.CallBack_Suspend.func  = Suspend;      /* Install suspend call back function into USB core */
  //gUSBCore.Power.CallBack_Suspend.uPara = (u32)NULL;

  USBDDesc_Init(&gUSBCore.Device.Desc);                 /* Initiate memory pointer of descriptor            */
  USBDClass_Init(&gUSBCore.Class);                      /* Initiate USB Class layer                         */
  USBDCore_Init(&gUSBCore);                             /* Initiate USB Core layer                          */

#if (LIBCFG_CKCU_HSI_NO_AUTOTRIM)
#else
  /* !!! NOTICE !!!
     Must turn on if the USB clock source is from HSI (PLL clock Source)
  */
  #if 0
  { /* Turn on HSI auto trim function                                                                       */
    CKCU_HSIAutoTrimClkConfig(CKCU_ATC_USB);
    CKCU_HSIAutoTrimCmd(ENABLE);
  }
  #endif
#endif

  NVIC_EnableIRQ(USB_IRQn);                             /* Enable USB device interrupt                      */
}

#if (LIBCFG_CKCU_USB_PLL)
/*********************************************************************************************************//**
 * @brief  Configure USB PLL
 * @retval None
 ************************************************************************************************************/
void USBPLL_Configuration(void)
{
  { /* USB PLL configuration                                                                                */

    /* !!! NOTICE !!!
       Notice that the local variable (structure) did not have an initial value.
       Please confirm that there are no missing members in the parameter settings below in this function.
    */
    CKCU_PLLInitTypeDef PLLInit;

    PLLInit.ClockSource = CKCU_PLLSRC_HSE;  // CKCU_PLLSRC_HSE or CKCU_PLLSRC_HSI
    PLLInit.CFG = CKCU_USBPLL_8M_48M;
    PLLInit.BYPASSCmd = DISABLE;
    CKCU_USBPLLInit(&PLLInit);
  }

  CKCU_USBPLLCmd(ENABLE);

  while (CKCU_GetClockReadyStatus(CKCU_FLAG_USBPLLRDY) == RESET);
  CKCU_USBClockConfig(CKCU_CKUSBPLL);
}
#endif

#define REMOTE_WAKEUP      (1)
/*********************************************************************************************************//**
  * @brief  Suspend call back function which enter DeepSleep1
  * @param  uPara: Parameter for Call back function
  * @retval None
  ***********************************************************************************************************/
void Suspend(u32 uPara)
{
  #if (REMOTE_WAKEUP == 1)
  u32 IsRemoteWakeupAllowed;
  #endif

  if (gIsLowPowerAllowed)
  {

    #if (REMOTE_WAKEUP == 1)
    /* Disable EXTI interrupt to prevent interrupt occurred after wakeup                                    */
    EXTI_IntConfig(KEY1_BUTTON_EXTI_CHANNEL, DISABLE);
    IsRemoteWakeupAllowed = USBDCore_GetRemoteWakeUpFeature(&gUSBCore);

    if (IsRemoteWakeupAllowed == TRUE)
    {
      /* Enable EXTI wake event and clear wakeup flag                                                       */
      EXTI_WakeupEventConfig(KEY1_BUTTON_EXTI_CHANNEL, EXTI_WAKEUP_LOW_LEVEL, ENABLE);
      EXTI_ClearWakeupFlag(KEY1_BUTTON_EXTI_CHANNEL);
    }
    #endif

    __DBG_USBPrintf("%06ld >DEEPSLEEP\r\n", ++__DBG_USBCount);

    // Add your procedure here which disable related IO to reduce power consumption
    // ..................
    //

    if ((gUSBCore.Info.CurrentStatus == USB_STATE_SUSPENDED) && ((HT_USB->CSR & 0xC0) == 0x40))   // D+ = 1, D- = 0
    {
      /* For Bus powered device, you must enter DeepSleep1 when device has been suspended. For self-powered */
      /* device, you may decide to enter DeepSleep1 or not depended on your application.                    */

      /* For the convenient during debugging and evaluation stage, the USBDCore_LowPower() is map to a null */
      /* function by default. In the real product, you must map this function to the low power function of  */
      /* firmware library by setting USBDCORE_ENABLE_LOW_POWER as 1 (in the ht32fxxxx_usbdconf.h file).     */
      USBDCore_LowPower();
    }

    // Add your procedure here which recovery related IO for application
    // ..................
    //

    __DBG_USBPrintf("%06ld <DEEPSLEEP\r\n", ++__DBG_USBCount);

    #if (REMOTE_WAKEUP == 1)
    if (EXTI_GetWakeupFlagStatus(KEY1_BUTTON_EXTI_CHANNEL) == SET)
    {
      __DBG_USBPrintf("%06ld WAKEUP\r\n", ++__DBG_USBCount);
      if (IsRemoteWakeupAllowed == TRUE && USBDCore_IsSuspend(&gUSBCore) == TRUE)
      {
        USBDCore_TriggerRemoteWakeup();
      }
    }

    if (IsRemoteWakeupAllowed == TRUE)
    {
      /* Disable EXTI wake event and clear wakeup flag                                                      */
      EXTI_WakeupEventConfig(KEY1_BUTTON_EXTI_CHANNEL, EXTI_WAKEUP_LOW_LEVEL, DISABLE);
      EXTI_ClearWakeupFlag(KEY1_BUTTON_EXTI_CHANNEL);
    }

    /* Clear EXTI edge flag and enable EXTI interrupt                                                       */
    EXTI_ClearEdgeFlag(KEY1_BUTTON_EXTI_CHANNEL);
    EXTI_IntConfig(KEY1_BUTTON_EXTI_CHANNEL, ENABLE);
    #endif
  }

  return;
}

#if (HT32_LIB_DEBUG == 1)
/*********************************************************************************************************//**
  * @brief  Report both the error name of the source file and the source line number.
  * @param  filename: pointer to the source file name.
  * @param  uline: error line source number.
  * @retval None
  ***********************************************************************************************************/
void assert_error(u8* filename, u32 uline)
{
  /*
     This function is called by IP library that the invalid parameters has been passed to the library API.
     Debug message can be added here.
     Example: printf("Parameter Error: file %s on line %d\r\n", filename, uline);
  */

  while (1)
  {
  }
}
#endif


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
