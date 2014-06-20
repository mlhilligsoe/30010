
#ifndef _LED_H_
#define _LED_H_

static int scrollSpeed = 750;
extern char updateLED;
extern char* TEKST; 

void initLED();

void displayTextOnLed();
void LEDsetString(char string[], char videoBuffer[][6], char index);
void LEDupdate(char column, char videoBuffer[][6], char columnIndex);


#endif /*_LED_H_*/