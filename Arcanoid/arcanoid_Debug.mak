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
#   -strict
#   -usrinc:"C:\Users\Hovedpude\Documents\30010\Arcanoid\include"
#   -NOwatch -cpu:Z8F6403
#   -asmsw:" -cpu:Z8F6403 -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1 -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -include:C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X -revaa"
CFLAGS = -sw:C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid_Debug.ccsw
# assembler options
#   -debug -define:_Z8F6403=1 -define:_Z8ENCORE_640_FAMILY=1
#   -define:_Z8ENCORE_F640X=1 -define:_MODEL_LARGE=1 -genobj -NOigcase
#   -include:"C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\std;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog;C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\Z8Encore_F640X"
#   -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt
#   -warn -NOzmasm -revaa -cpu:Z8F6403
AFLAGS = -sw:C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid_Debug.asmsw

OUTDIR = C:\Users\Hovedpude\Documents\30010\Arcanoid\

Debug: arcanoid

deltarget: 
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid.lod  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid.lod

clean: 
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid.lod  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid.lod
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\main.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\main.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\ansi.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\ansi.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\game.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\game.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\input.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\input.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\LED.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\LED.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\menu.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\menu.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\printFix.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\printFix.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\SinLUT.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\SinLUT.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\graphics.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\graphics.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\gamePhysics.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\gamePhysics.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\level.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\level.obj
	@if exist C:\Users\Hovedpude\Documents\30010\Arcanoid\timer.obj  \
            del C:\Users\Hovedpude\Documents\30010\Arcanoid\timer.obj

rebuildall: clean Debug

relink: deltarget Debug

LIBS = 

OBJS =  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\main.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\ansi.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\game.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\input.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\LED.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\menu.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\printFix.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\SinLUT.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\graphics.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\gamePhysics.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\level.obj  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\timer.obj

arcanoid: $(OBJS)
	 $(LINK)  @C:\Users\Hovedpude\Documents\30010\Arcanoid\arcanoid_Debug.linkcmd

C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.asm  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\ez8dev.inc  \
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\gpio.inc
	 $(ASM)  $(AFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\zsldevinit.asm

C:\Users\Hovedpude\Documents\30010\Arcanoid\main.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\main.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\GAMEPH~1.H  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\input.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\printFix.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\timer.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\main.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\ansi.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\ansi.c  \
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
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\ansi.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\game.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\game.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\level.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\game.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\input.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\input.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\input.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\LED.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\LED.c  \
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
            C:\PROGRA~2\ZiLOG\ZDSII_~1.3\include\zilog\uartdefs.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\LED.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\menu.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\menu.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\graphics.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\menu.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\menu.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\printFix.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\printFix.c  \
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
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\printFix.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\SinLUT.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\SinLUT.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\sinLUT.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\SinLUT.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\graphics.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\graphics.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\graphics.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\timer.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\graphics.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\gamePhysics.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\gamePhysics.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\game.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\GAMEPH~1.H  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\graphics.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\sinLUT.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\struct.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\gamePhysics.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\level.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\level.c  \
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
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\level.c

C:\Users\Hovedpude\Documents\30010\Arcanoid\timer.obj :  \
            C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\timer.c  \
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
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\ansi.h  \
            C:\Users\HOVEDP~1\DOCUME~1\30010\Arcanoid\include\timer.h
	 $(CC)  $(CFLAGS) C:\Users\Hovedpude\Documents\30010\Arcanoid\include\src\timer.c

