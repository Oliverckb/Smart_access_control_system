@REM This batch file has been generated by the IAR Embedded Workbench
@REM C-SPY Debugger, as an aid to preparing a command line for running
@REM the cspybat command line utility using the appropriate settings.
@REM
@REM Note that this file is generated every time a new debug session
@REM is initialized, so you may want to move or rename the file before
@REM making changes.
@REM
@REM You can launch cspybat by typing the name of this batch file followed
@REM by the name of the debug file (usually an ELF/DWARF or UBROF file).
@REM
@REM Read about available command line parameters in the C-SPY Debugging
@REM Guide. Hints about additional command line parameters that may be
@REM useful in specific cases:
@REM   --download_only   Downloads a code image without starting a debug
@REM                     session afterwards.
@REM   --silent          Omits the sign-on message.
@REM   --timeout         Limits the maximum allowed execution time.
@REM 


"D:\IAR_ARM\Main\common\bin\cspybat" "D:\IAR_ARM\Main\arm\bin\armproc.dll" "D:\IAR_ARM\Main\arm\bin\armpemicro.dll"  %1 --plugin "D:\IAR_ARM\Main\arm\bin\armbat.dll" --macro "D:\IAR_ARM\Main\arm\config\debugger\Freescale\Trace_Kxx.dmac" --flash_loader "D:\IAR_ARM\Main\arm\config\flashloader\Freescale\FlashK60Xxxx.board" --backend -B "--endian=little" "--cpu=Cortex-M4" "--fpu=None" "-p" "D:\IAR_ARM\Main\arm\CONFIG\debugger\Freescale\MK60DN512Zxxx10.ddf" "--drv_verify_download" "--semihosting=none" "--device=MK60DN512Zxxx10" "--pemicro_interface_type=OSJtag" "--pemicro_reset_delay=" "--drv_communication=USB1" "--pemicro_jtag" 


