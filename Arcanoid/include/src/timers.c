#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timers.h"
#include "ansi.h"
#include "input.h"
#include "LED.h"

void reset(struct stopwatch* time){
time->H =0;
time->M =0;
time->S =0;
time->C =0;
}


void initAll(){
DI();
//initTimer0(); // Init and start timer0: 10ms
initTimer1();
LEDinit();
EI();
}
void initTimer0(){
T0CTL &= 0x7F; //Timer disable
T0CTL = 0x39; // timer setup Continious mode and prescale 128
T0H = 0x00; // skriver start betingelse 0001
T0L = 0x01;
T0RH = 0x05; // Reload værdi = 1440 = 0x05A0 dvs. 1/100 s
T0RL = 0xA0;
SET_VECTOR(TIMER0, timer0int); //ved interrupt ved timer0, køres interrupt funktionen defineret ovenfor.
IRQ0ENH |= 0x20; // enable Timer0 interrupt, and set nominal priority
IRQ0ENL &= 0xDF; // "
T0CTL |= 0x80;  // Timer enable
}

void initTimer1(){
T1CTL &= 0x7F; //Timer disable
T1CTL = 0x39; // timer setup Continious mode and prescale 128
T1H = 0x00; // skriver start betingelse 0001
T1L = 0x01;
T1RH = 0x00; // Reload værdi = 72= 0x0048 dvs. 1/2000 s
T1RL = 0x48;
SET_VECTOR(TIMER1, timer1int); //ved interrupt ved timer0, køres interrupt funktionen defineret ovenfor.
IRQ0ENH &= 0xBF; // enable Timer1 interrupt, and set low priority due to display update being less important.
IRQ0ENL |= 0x40; // "
T1CTL |= 0x80; // Timer enable
}

#pragma interrupt
void timer0int() {

timer.C++;
if (timer.C >= 100){
	timer.C = 0;
	timer.S++;
}
if (timer.S >= 60){
	timer.S = 0;
	timer.M++;
}
if (timer.M >= 60){
	timer.M = 0;
	timer.H++;
}

//EI();
}

#pragma interrupt
void timer1int() {
updateLED = 1;
// insert display update flag.
}

void drawStopwatch(){
window(1,1,36,6,"Stop Watch",1);
gotoxy(3,3);
printf("Time since Start :");
gotoxy(3,4);
printf("Split time 1     :");
gotoxy(3,5);
printf("Split time 2     :");

gotoxy(22,4);
	printf("-:--:--.--");
gotoxy(22,5);
    printf("-:--:--.--");
}

void updateStopwatch(char* enabled, char* current, char* last, char* change){

*current = readkey();
*change =(~(*last) & (*current));

if(*change == 1){
	if (*enabled){
		DI(); // Enable interrupt = stopwatch start.
		*enabled = 0;
	}
	else{
	    EI(); 
	    *enabled =1;
	  }
	}
if(*change == 2){
	gotoxy(22,4);
	printf("%01d:%02d:%02d.%02d",timer.H,timer.M,timer.S,timer.C);}
if(*change == 4){
	gotoxy(22,5);
	printf("%01d:%02d:%02d.%02d",timer.H,timer.M,timer.S,timer.C);}
if(*current == 6){
DI();
reset(&timer);

	gotoxy(22,4);
	printf("%01d:%02d:%02d.%02d",timer.H,timer.M,timer.S,timer.C);
	gotoxy(22,5);
	printf("%01d:%02d:%02d.%02d",timer.H,timer.M,timer.S,timer.C);
	*enabled = 0;
}
gotoxy(22,3);
printf("%01d:%02d:%02d.--",timer.H,timer.M,timer.S);
*last = *current;
}