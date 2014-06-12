
#ifndef _TIMERS_H_
#define _TIMERS_H_

struct stopwatch{
	char H;
	char M;
	char S;
	char C;
};

extern struct stopwatch timer;

void initAll();
void reset(struct stopwatch* time);
void initTimer0();
void initTimer1();
void timer0int();
void timer1int();
void drawStopwatch();
void updateStopwatch(char* enabled, char* current, char* last, char* change);

#endif /*_TIMERS_H_*/