/**
 @page Tips_StackOnTop

 @verbatim
 * @file    Tips/StackOnTop/readme.txt
 * @version V1.01
 * @date    2024-03-26
 * @brief   Description of Tips StackOnTop example.
 @endverbatim

@par Example Description:

This example will shift the Stack Point to the top of SRAM, and then display the address of stack data by serial port.

@par Directory Contents:

- Tips/StackOnTop/main.c                           Main program
- Tips/StackOnTop/ht32fxxxxx_nn_it.c               Interrupt handlers

@par Hardware and Software Environment:

- This example can be run on HT32 Series development board.
- You need a terminal software such as TeraTerm (https://ttssh2.osdn.jp/).
- Connect a null-modem female/female RS232 cable between the UxART and PC serial port.
  Terminal configuration:
  - Word Length = 8 Bits
  - One Stop Bit
  - No parity
  - BaudRate = 115200 baud
  - Flow control: None

@par Firmware Disclaimer Information

1. The customer hereby acknowledges and agrees that the program technical documentation, including the
   code, which is supplied by Holtek Semiconductor Inc., (hereinafter referred to as "HOLTEK") is the
   proprietary and confidential intellectual property of HOLTEK, and is protected by copyright law and
   other intellectual property laws.

2. The customer hereby acknowledges and agrees that the program technical documentation, including the
   code, is confidential information belonging to HOLTEK, and must not be disclosed to any third parties
   other than HOLTEK and the customer.

3. The program technical documentation, including the code, is provided "as is" and for customer reference
   only. After delivery by HOLTEK, the customer shall use the program technical documentation, including
   the code, at their own risk. HOLTEK disclaims any expressed, implied or statutory warranties, including
   the warranties of merchantability, satisfactory quality and fitness for a particular purpose.

 * <h2><center>Copyright (C) Holtek Semiconductor Inc. All rights reserved</center></h2>
 */
