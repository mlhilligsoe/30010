#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timer.h"
#include "ansi.h"
#include "LED.h"

char timer0Flag = 0;
char timer1Flag = 0;

void initTimers(){
DI(); // Disable interrupt
initTimer0();
initTimer1();
EI();// Enable. interrupt
}

void initTimer0(){

T0CTL &= 0x7F; //Timer disable
T0CTL = 0x39; // timer setup Continious mode and prescale 128
T0H = 0x00; // skriver start betingelse 0000
T0L = 0x00;
T0RH = 0x05; // Reload værdi = 1440 = 0x05A0 dvs. 1/100 s
T0RL = 0xA0;
SET_VECTOR(TIMER0, timer0int); //ved interrupt ved timer0, køres interrupt funktionen defineret ovenfor.
IRQ0ENH |= 0x20; // enable Timer0 interrupt, and set nominal priority
IRQ0ENL &= 0xDF; // 
T0CTL |= 0x80;  // Timer enable

}

#pragma interrupt
void timer0int() {
	timer1Flag = 1;
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
void timer1int() {
	timer0Flag = 1;
}