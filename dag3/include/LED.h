
#ifndef _LED_H_
#define _LED_H_

extern char updateLED;
static char* TEKST = "    #DTU-SPACE <<30010 Programmeringsprojekt>> #DTU-SPACE "; 

void LEDinit();

void displayTextOnLed();
void LEDsetString(char string[], char videoBuffer[][6], char index);
void LEDupdate(char column, char videoBuffer[][6], char columnIndex);


#endif /*_LED_H_*/