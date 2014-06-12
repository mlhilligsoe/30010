#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "printFix.h"
#include "SinLUT.h"
#include "input.h"
#include "timers.h"
#include "display.h"

//Test

void main(){

	/***************************/
	/* Initialization          */
	/***************************/

	// Initialize LED variables
	char videoBuffer[5][6] = {0};	// Initializes a '0' array

	// Initialize Menu variables
	char inMenu = 0; 				// 0: Start Menu; >0: Other Menus; <0: Game
	char selection = 0; 			// Defines the current menu selection

	// Initialize input variables
	char input = 0;					// 1:'00000001' for btn1 pressdown; 2:'00000010' for btn2 pressdown; 3:'00000100' for btn3 pressdown;

	// Initialize terminal connection
	init_uart(_UART0,_DEFFREQ,_DEFBAUD); // set-up UART0 to 57600, 8n1

	// Initialize time and input (µP registers)
	initTimer();
	initInput();

	// Initialize Game Menu
	createMenu(selection, inMenu);

	/***************************/
	/* Main Loop	           */
	/***************************/
	while( 1 ){

		// Get input
		getInput(&input);

		// If in Menu
		if(inMenu >= 0){

			// Apply Menu action if any input is given
			if(input != 0)
				actionMenu(input, &selection, inMenu);

		}

		// Else if not in Menu
		else if( inMenu < 0){
			// Test if pausing (btn1 pressed)
			if(input & 0x01 == 0x01) {
				pause(&inMenu);
			}

			// Else continue game
			else {

				// Update positions and redraw ball & player
				updatePositions(input, &ball, &player);

				// Test for collisions and redraw level
				testForCollisions(&ball, &player, &level);

				// Test if player dead or level completed, and reset.
				//If true, gameLost or gameWon will update ball, player and level before sending the player back to a menu.
				if(player.lives <= 0)
					gameLost(&inMenu, &ball, &player, &level);
				else if(level.lives <= 0)
					gameWon(&inMenu, &ball, &player, &level);

			}
		}

		// If not in menu or game, something went wrong. Break while loop and end application.
		else{
			break;
		}

	} // End of main while loop
} // End of main()
