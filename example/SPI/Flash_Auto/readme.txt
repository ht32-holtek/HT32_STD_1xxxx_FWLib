/**
 @page SPI_Flash_Auto

 @verbatim
 * @file    SPI/Flash_Auto/readme.txt
 * @version V2.00
 * @date    2020-08-11
 * @brief   Description of the SPI Flash example (with auto detection).
 @endverbatim

@par Example Description:

This example describes how to use the utilities SPI driver to communicate with MX25L1606E SPI flash.

The SPI is configured as master mode with an 8-bit data size. The SPI clock is set to HCLK/2 MHz.

The test address of SPI flash is defined by the "FLASH_TEST_ADDR". If all the test are passed, LED1 ~ LED3
will be turned on.

Test Steps
  - Read the Flash ID from the SPI flash and compare it. If the ID is correct, turn on the LED1.
  - Clear Block Protection bit by write the status register.
  - Erase sector on the address "FLASH_TEST_ADDR".
  - Program the data of "gWrite_Buffer[]" into the address "FLASH_TEST_ADDR" of the flash.
  - Read the Flash data to the variable, "gRead_Buffer[]" by dual read function.
  - Do the flash verification by compare the "gWrite_Buffer[]" and "gRead_Buffer[]", turn on the LED2 if
    verification is passed.
  - Erase sector again on the address "FLASH_TEST_ADDR".
  - Do the flash blank check (by normal read function), turn on the LED3 if the blank check is passed.

@par Directory Contents:

- SPI/Flash_Auto/main.c                                     Main program
- SPI/Flash_Auto/ht32fxxxxx_nn_it.c                         Interrupt handlers

@par Hardware and Software Environment:

- This example can be run on the HT32 series development kit.
- The expansion board such as ESK32-2x001 is required, refer to the user manual for the jumper settings.
- This example requires external component on the expansion board but some development board (with the
  "USE_HT32XXXXXX_DVB" define) can not use with it directly. The extra jumper/wired connections may required
  to use this example.

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
