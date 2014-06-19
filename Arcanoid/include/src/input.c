#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"


void initInput(){
	PBDD = 0x2A; // port PB1, PB3, PB5 som knap input.
	PBAF = 0x80; // port  PB7 er ADC
}


int getInput(){
	int i, BTN, AJOY, input;
	BTN = 0;

	//BTN |= (int)((~PFIN & 0x80) >> 7);
	//BTN |= (int)((~PFIN & 0x40) >> 5);
	//BTN |= (int)((~PDIN & 0x08) >> 1);
	
	BTN |= (int)((~PBIN & 0x02) << 1); // Isolerer BTN1
	BTN |= (int)((~PBIN & 0x08) >> 3); //  Isolerer BTN2
	BTN |= (int)((~PBIN & 0x20) >> 4); //  Isolerer BTN3

	
	// Initialisering af ADC på pin PB7,
	ADCCTL = 0xB7;
	// Wait for ADC to finish.
	for(i = 0; i < 300; i++){
		;
	}
	
	// Read converted signal
	AJOY = 0;
	AJOY = ((int) ADCD_H << 2);
	AJOY |= ((int) ADCD_L >> 6);
	
	input = 0;
	input = BTN | (AJOY << 5 );

	return input; // input is 16 bit, the 3 buttons are 0000 0000 0000 0xxx. The slider is xxxx xxxx xx00 0000.
}

int inputChange(int inputOld, int inputNew){

	return (~inputOld & inputNew & 0x0007) | (inputNew & 0xFFC0);

}
