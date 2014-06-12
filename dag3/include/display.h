
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

extern char updateDisplay;
static char* TEKST = "    #DTU-SPACE <<30010 Programmeringsprojekt>> #DTU-SPACE "; 

void LEDinit();

void displayTextOnLed();
void LEDsetString(char string[], char videoBuffer[][6], char index);
void LEDupdate(char column, char videoBuffer[][6], char columnIndex);


#endif /*_DISPLAY_H_*/