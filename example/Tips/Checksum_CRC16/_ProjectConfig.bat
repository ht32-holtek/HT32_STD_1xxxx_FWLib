REM /*********************************************************************************************************//**
REM * @file    _ProjectConfig.bat
REM * @version $Rev:: 9096         $
REM * @date    $Date:: 2025-06-17 #$
REM * @brief   Project configure file.
REM *************************************************************************************************************

REM README
REM This file provides the function below. It shall be use with "_CreateProject.bat"
REM  1. Remove Project_xxxxx files that do not supported by the example/application code (xxxxx is model name).
REM  2. Change RO, RW Based address.
REM  3. Change Stack and Heap Size.
REM  4. Change the C include path.
REM  5. Change the C define
REM  6. Change the linker Script usage or name
REM  7. Apply specify modification by customer.
REM


REM Remove Project_xxxxx files that do not supported by the example/application code
REM ============================================================================
REM For device support, see _ProjectConfig.ini

rmdir /S /Q "emStudiov4"
rmdir /S /Q "EWARM"
rmdir /S /Q "EWARMv8"
rmdir /S /Q "GNU_ARM"
rem rmdir /S /Q "HT32-IDE"
rem rmdir /S /Q "MDK_ARM"
rem rmdir /S /Q "MDK_ARMv5"
rem rmdir /S /Q "MDK_ARMv537"
rmdir /S /Q "SourceryG++Lite"
REM ============================================================================




REM !!! NOTICE: Do not put any space between the "=" !!!
REM !!!         "SET VAR=VALUE" is OK
REM !!!         "SET VAR = VALUE" is not allowed




REM Change RO, RW Based address
REM ============================================================================
SET HT_CHANGE_RO_RW=0
SET HT_RO_ADDR=0x00000000
SET HT_RW_ADDR=0x20000000
REM ============================================================================


REM Change Stack and Heap Size
REM ============================================================================
SET HT_CHANGE_STACK_HEAP=0
SET HT_STACK_SIZE=512
SET HT_HEAP_SIZE=0
REM ============================================================================


REM Change include path
REM Note:
REM     1. HT_EXTRA_INCLUDE shall be separated by semicolons (;)
REM        Example HT_EXTRA_INCLUDE=..\Test1;..\Extra_Include
REM ============================================================================
SET HT_CHANGE_INCLUDE=0
SET HT_EXTRA_INCLUDE=..\PATH1;..\PATH2
REM ============================================================================


REM Change C define
REM Note:
REM     1. HT_EXTRA_CDEFINE shall be separated by comma and space (, )
REM        Example HT_EXTRA_CDEFINE=DEFINE1, DEFINE2
REM ============================================================================
SET HT_CHANGE_CDEFINE=0
SET HT_EXTRA_CDEFINE=DEFINE1, DEFINE2
REM ============================================================================


REM Change Linker Script file
REM Note:
REM     1. The path is relative to the project file folder, such as "HT32-IDE\" or "MDK_ARMv5\".
REM ============================================================================
SET HT_CHANGE_LINKER_SCRIPT=0
SET HT_LINKER_NAME_KEIL=linker.lin
SET HT_LINKER_NAME_IAR=linker.icf
SET HT_LINKER_NAME_GNU=..\GNU\linker.ld
SET HT_LINKER_NAME_HT32_IDE=GNU_ARM\linker.ld
SET HT_LINKER_NAME_SES=../SES/linker_test.icf
SET HT_LINKER_NAME_SourceryG=..\SourceryG\linker_test.ld
REM ============================================================================


REM Apply specify modification
REM Example: (":x0a" for newline "\n")
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" MDK_ARM\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" MDK_ARMv5\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" MDK_ARMv537\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" EWARM\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" EWARMv8\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" GNU_ARM\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
rem gsar.exe -s"SEARCH_STRING:x0a" -r"REPLACE_STRING:x0a" SourceryG++Lite\*_FILENAME_KEYWORD_*._ATTACHMENT_NAME_ -o
REM ============================================================================
rem Edit your code here....
REM ============================================================================
gsar.exe -s"<Flash4></Flash4>" -r"<Flash4>.\CRC_LOAD.ini</Flash4>" MDK_ARM\Project_*.uvproj -o
gsar.exe -s"<Flash4></Flash4>" -r"<Flash4>.\CRC_LOAD.ini</Flash4>" MDK_ARMv5\Project_*.uvprojx -o
gsar.exe -s"<Flash4></Flash4>" -r"<Flash4>.\CRC_LOAD.ini</Flash4>" MDK_ARMv537\Project_*.uvprojx -o

gsar.exe -s"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>0</RunUserProg2>" -r"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>1</RunUserProg2>" MDK_ARM\Project_*.uvproj -o
gsar.exe -s"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>0</RunUserProg2>" -r"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>1</RunUserProg2>" MDK_ARMv5\Project_*.uvprojx -o
gsar.exe -s"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>0</RunUserProg2>" -r"<AfterMake>:x0a            <RunUserProg1>1</RunUserProg1>:x0a            <RunUserProg2>1</RunUserProg2>" MDK_ARMv537\Project_*.uvprojx -o

gsar.exe -s"<UserProg2Name>fromelf --text -c -o \":x21L.text\" \":x21L\"</UserProg2Name>" -r"<UserProg2Name>..\_Tools\srec_make_combo.bat keil @L $D \"$J\"</UserProg2Name>" MDK_ARM\Project_*.uvproj -o
gsar.exe -s"<UserProg2Name>fromelf --text -c -o \":x21L.text\" \":x21L\"</UserProg2Name>" -r"<UserProg2Name>..\_Tools\srec_make_combo.bat keil @L $D \"$J\"</UserProg2Name>" MDK_ARMv5\Project_*.uvprojx -o
gsar.exe -s"<UserProg2Name>fromelf --text -c -o \":x21L.text\" \":x21L\"</UserProg2Name>" -r"<UserProg2Name>..\_Tools\srec_make_combo.bat keil @L $D \"$J\"</UserProg2Name>" MDK_ARMv537\Project_*.uvprojx -o

gsar.exe -s"REM ADD_YOUR_CODE_HERE" -r"REM ADD_YOUR_CODE_HERE:x0d:x0a..\..\..\_Tools\srec_make_combo.bat :x25VAR_MODE:x25 :x25VAR_OUTPUT_NAME:x25 :x25VAR_IC_NAME:x25 :x25VAR_KEIL_PATH:x25" HT32-IDE\afterbuild.bat -o
