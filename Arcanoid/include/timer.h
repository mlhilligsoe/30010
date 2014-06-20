
#ifndef _TIMER_H_
#define _TIMER_H_

extern char timer0Flag;
extern char timer1Flag;

void initTimers();
void initTimer0();
void initTimer1();
void timer0int();
void timer1int();


#endif /*_TIMER_H_*/