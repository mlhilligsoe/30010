#ifndef _LED_H_
#define _LED_H_

static int scrollSpeed = 100;

void initLED();

void displayTextOnLed(char videoBuffer[][6], char* text, char* cColumn,
		char* columnIndex, char* LEDIndex, int* runs, char scroll);
void LEDsetString(char string[], char videoBuffer[][6], char index);
void LEDupdate(char column, char videoBuffer[][6], char columnIndex);

#endif /*_LED_H_*/
