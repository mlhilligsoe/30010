#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "printFix.h"
#include "SinLUT.h"
#include "input.h"
#include "timers.h"
#include "LED.h"


//Nice
void main(){

char videoBuffer[5][6] = {0}; //init et '0' array.
char enabled = 0, current, last = 0, change; // Initialize stopwatch variables

initAll();
init_uart(_UART0,_DEFFREQ,_DEFBAUD); // set-up UART0 to 57600, 8n1

LEDsetString(TEKST, videoBuffer, 0);  //Loader initial teksten ind i displayet.
		//Running loop
while( 1 ) {
displayTextOnLed(videoBuffer);
}
do{}while(1 != 2);
}
