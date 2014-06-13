#
# ZDS II Make File - arcanoid, Debug
#

CC = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8cc
ASM = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8asm
LINK = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8link
LIB = @C:\PROGRA~2\ZiLOG\ZDSII_~1.3\bin\eZ8lib

# compiler options
#   -alias -asm -bitfieldsize:32 -charsize:8 -const:RAM -debug
#   -define:_Z8F6403 -define:_Z8ENCORE_640_FAMILY
#   -define:_Z8ENCORE_F640X -define:_MODEL_LARGE -doublesize:32
#   -NOexpmac -floatsize:32 -NOfplib -genprintf -NOglobalcopy
#   -NOglobalcse -NOglobalfold -intrinsic -intsize:16 -intsrc -NOjmpopt
#   -NOkeepasm -NOkeeplst -NOlist -NOlistinc -localcopy -localcse
#   -localfold -longsize:32 -NOloopopt -maxerrs:50 -model:L -NOoptlink
#   -optsize -peephole -NOpromote -quiet -regvar -revaa -NOsdiopt
#   -shortsize:16
#   -stdinc:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -strict -usrinc:"C:\Users\Erik\Documents\30010\Arcanoid\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Erik\Documents\30010\Arcanoid\arcanoid_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Erik\Documents\30010\Arcanoid\arcanoid_Debug.asmsw

OUTDIR = C:\Users\Erik\Documents\30010\Arcanoid\

Debug: arcanoid

deltarget: 
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\arcanoid.lod  \
            del C:\Users\Erik\Documents\30010\Arcanoid\arcanoid.lod

clean: 
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\arcanoid.lod  \
            del C:\Users\Erik\Documents\30010\Arcanoid\arcanoid.lod
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\main.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\main.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\ansi.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\ansi.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\game.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\game.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\input.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\input.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\LED.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\LED.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\menu.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\menu.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\printFix.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\printFix.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\SinLUT.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\SinLUT.obj
	@if exist C:\Users\Erik\Documents\30010\Arcanoid\timers.obj  \
            del C:\Users\Erik\Documents\30010\Arcanoid\timers.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\main.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\ansi.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\game.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\input.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\LED.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\menu.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\printFix.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\SinLUT.obj  \
            C:\Users\Erik\Documents\30010\Arcanoid\timers.obj

arcanoid: $(OBJS)
	 $(LINK)  @C:\Users\Erik\Documents\30010\Arcanoid\arcanoid_Debug.linkcmd

C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\zsldevinit.asm

C:\Users\Erik\Documents\30010\Arcanoid\main.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\main.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\input.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\printFix.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\struct.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\timers.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\main.c

C:\Users\Erik\Documents\30010\Arcanoid\ansi.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\ansi.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\printFix.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\ansi.c

C:\Users\Erik\Documents\30010\Arcanoid\game.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\game.c  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\game.c

C:\Users\Erik\Documents\30010\Arcanoid\input.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\input.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\input.c

C:\Users\Erik\Documents\30010\Arcanoid\LED.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\LED.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STRING.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\LED.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\charset.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\timers.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\LED.c

C:\Users\Erik\Documents\30010\Arcanoid\menu.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\menu.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\menu.c

C:\Users\Erik\Documents\30010\Arcanoid\printFix.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\printFix.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\printFix.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\printFix.c

C:\Users\Erik\Documents\30010\Arcanoid\SinLUT.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\SinLUT.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\SinLUT.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\SinLUT.c

C:\Users\Erik\Documents\30010\Arcanoid\timers.obj :  \
            C:\Users\Erik\Documents\30010\Arcanoid\include\src\timers.c  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\FORMAT.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std\STDARG.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\defines.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\dmadefs.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\SIO.H  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uart.h  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\LED.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\input.h  \
            C:\Users\Erik\DOCUME~1\30010\Arcanoid\include\timers.h
	 $(CC)  $(CFLAGS) C:\Users\Erik\Documents\30010\Arcanoid\include\src\timers.c

