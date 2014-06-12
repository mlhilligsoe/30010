#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timers.h"
#include "display.h"
#include "charset.h"
#include "ansi.h"
#include <string.h>

void LEDinit(){
PEDD = 0x00;
PGDD = 0x00; //dara direction

//initTimer1(); //opsætter timer1 og starter den

}
char cColumn = 0, columnIndex = 0, displayIndex = 0;
int runs = 0;
int scrollSpeed = 750;

void displayTextOnLed(char videoBuffer[][6] ){

		//Udregner hvilken kolonne på samtlige displays der skal opdateres.
cColumn = (cColumn + 1) % 5;  	

		//Udregner hvor mange kolonner teksten skal forskydes med fra videobufferen
if ( runs == 0 ){			
	columnIndex = (columnIndex + 1) % 6;

		//Udregner hvornår videoBuffer skal opdateres
if( columnIndex == 0 ){				
	displayIndex = (displayIndex +1) % strlen(TEKST);
	LEDsetString(TEKST, videoBuffer, displayIndex);
	}
}
runs = (runs + 1) % scrollSpeed;

LEDupdate(cColumn, videoBuffer, columnIndex);

}

void LEDsetString(char string[], char videoBuffer[][6], char index){
	char i = 0;
	char value;

	while(i < 5){	
		
		value = string[(i+index) %  strlen(TEKST)] - 32; // array index value of ascii char in charset.h
		videoBuffer[i][0] = character_data[value][0];  //burde læse bogstavet ind i videobuffer
		videoBuffer[i][1] = character_data[value][1];
		videoBuffer[i][2] = character_data[value][2];
		videoBuffer[i][3] = character_data[value][3];
		videoBuffer[i][4] = character_data[value][4];
		i++;
	}
}

void LEDupdate(char column, char videoBuffer[][6], char columnIndex){


	if(updateDisplay != 0){
	
	

	switch (column){
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
		PGOUT = (*(&videoBuffer[0][column]+columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
		PEOUT |= 0x80;
		PEOUT &= 0x7F; //latcher Display 1.

		PGOUT = (*(&videoBuffer[1][column]+columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
		PGOUT |= 0x80;
		PGOUT &= 0x7F; //latcher Display 2.

		PGOUT = (*(&videoBuffer[2][column]+columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
		PEOUT |= 0x20;
		PEOUT &= 0xDF; //latcher Display 3.

		PGOUT = (*(&videoBuffer[3][column]+columnIndex) & 0x7F); // sikrer at PGOUT[7] dvs. D2 latch forbliver 0
		PEOUT |= 0x40;
		PEOUT &= 0xBF; //latcher Display 4.
	
	
	updateDisplay = 0;
	
	}
	
}
