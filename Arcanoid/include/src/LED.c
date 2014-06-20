#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
//#include "timer.h"
#include "LED.h"
#include "charset.h"
#include "ansi.h"
#include <string.h>

char updateLED = 0;

void initLED() {
	PEDD = 0x00; //data direction
	PGDD = 0x00;
	//initTimer1(); //opsætter timer1 og starter den
}

void displayTextOnLed(char videoBuffer[][6], char* text, char* cColumn,
		char* columnIndex, char* LEDIndex, int* runs, char scroll) {

	//Udregner hvilken kolonne på samtlige displays der skal opdateres.
	*cColumn = (*cColumn + 1) % 5;

	//Udregner hvor mange kolonner teksten skal forskydes med fra videobufferen
	if (*runs == 0) {
		*columnIndex = (*columnIndex + 1) % 6;

		//Udregner hvornår videoBuffer skal opdateres
		if (*columnIndex == 0) {
			*LEDIndex = (*LEDIndex + 1) % strlen(text);
			if(scroll != 0)
				LEDsetString(text, videoBuffer, *LEDIndex);
			else
				LEDsetString(text, videoBuffer, 0);
		}
	}
	*runs = (*runs + 1) % scrollSpeed;
	
	if(scroll != 0)
		LEDupdate(*cColumn, videoBuffer, *columnIndex);
	else
		LEDupdate(*cColumn, videoBuffer, 0);
}

void LEDsetString(char text[], char videoBuffer[][6], char index) {
	char i = 0;
	char value;

	while (i < 5) {

		value = text[(i + index) % strlen(text)] - 32; // array index value of ascii char in charset.h
		videoBuffer[i][0] = character_data[value][0]; //burde læse bogstavet ind i videobuffer
		videoBuffer[i][1] = character_data[value][1];
		videoBuffer[i][2] = character_data[value][2];
		videoBuffer[i][3] = character_data[value][3];
		videoBuffer[i][4] = character_data[value][4];
		i++;
	}
}

void LEDupdate(char column, char videoBuffer[][6], char columnIndex) {

	switch (column) {
	case 0:
		PEOUT &= 0xEF;
		PEOUT |= 0x0F; // column 4 active
		break;
	case 1:
		PEOUT &= 0xF7;
		PEOUT |= 0x17; // column 3 active
		break;
	case 2:
		PEOUT &= 0xFB;
		PEOUT |= 0x1B; // column 2 active
		break;
	case 3:
		PEOUT &= 0xFD;
		PEOUT |= 0x1D; // column 1 active
		break;
	case 4:
		PEOUT &= 0xFE;
		PEOUT |= 0x1E; // column 0 active
		break;
	}
	PGOUT = (*(&videoBuffer[0][column] + columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
	PEOUT |= 0x80;
	PEOUT &= 0x7F; //latcher Display 1.

	PGOUT = (*(&videoBuffer[1][column] + columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
	PGOUT |= 0x80;
	PGOUT &= 0x7F; //latcher Display 2.

	PGOUT = (*(&videoBuffer[2][column] + columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
	PEOUT |= 0x20;
	PEOUT &= 0xDF; //latcher Display 3.

	PGOUT = (*(&videoBuffer[3][column] + columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
	PEOUT |= 0x40;
	PEOUT &= 0xBF; //latcher Display 4.

}
