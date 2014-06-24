#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "LED.h"
#include "input.h"
#include "timer.h"
#include "menu.h"
#include "game.h"
#include "struct.h"
#include "gamePhysics.h"

void main(){

	/***************************/
	/* Initialization          */
	/***************************/

	// Initialize LED variables
	char videoBuffer[5][6] = {0};	// Initializes a '0' array
	char* LEDText = "    Arconoid Group 14 ";
	char column = 0, columnIndex = 0, LEDIndex = 0;
	int runs = 0;

	// Initialize Menu variables
	char menu = 1; 				// 0: Start Menu; >0: Other Menus; <0: Game
	char selection = 0; 			// Defines the current menu selection
	struct Player player;
	struct Ball ball;
	struct Level level;

	// Initialize input variables
	int input = 0, inputOld = 0, inputNew = 0;					// 1:'00000001' for btn1 pressdown; 2:'00000010' for btn2 pressdown; 3:'00000100' for btn3 pressdown;

	// Initialize terminal connection
	init_uart(_UART0,_DEFFREQ,115200); // set-up UART0 to 57600, 8n1

	// Initialize time and input (µP registers)
	initTimers();
	initInput();
	initLED();
	LEDsetString(LEDText, videoBuffer, 0);

	player.x = (long)((input >> 5)/13 + 2) << 16;
	
	// Initialize Game Menu
	createMenu(menu, &selection);

	/***************************/
	/* Main Loop	           */
	/***************************/
	while( 1 ){
		if(timer0Flag != 0)
		{
			
		// Get input
		inputOld = inputNew;
		inputNew = getInput();
		input = inputChange(inputOld, inputNew);
	
		// If in Menu
		if(menu > 0){
			sprintf(LEDText, "  Arconoid Group 14  ");
			
			// Apply Menu action if any input is given
			if( (input & 0x0007) != 0)
				menuInput( (input & 0x0007) , &selection, &menu, &level, &player, &ball);

		}

		// Else if menu == 0, game is running
		else if( menu == 0){
			sprintf(LEDText, "%04d",player.points);
			// Test if player dead or level completed, and reset.
			//If true, gameLost or gameWon will update ball, player and level before sending the player back to a menu.
			if(player.lifes <= 0)
				gameLost(&player, &level, &menu, &selection);
			else if(level.lifes <= 0)
				gameWon(&player, &level, &ball, &menu, &selection);	
		
			// Test if pausing (red button pressed) or boss key (all buttons pressed)
			else if((input & 0x0007) == 4) {
				pause(&menu, &selection);
			}
			else if((input & 0x0007) == 2) {
				boss(&menu, &selection);
			}			
			
			// Update game
			else {
				// Update positions and redraw ball & player
				updatePositions(input, &player, &ball);

				// Test for collisions and redraw level
				testForCollisions(&player, &ball, &level);
			}
		}

		// If menu < 0, something went wrong.
		else{
			break;
		}

		timer0Flag = 0;
	} // End of if loop for timerFlag
	
	// Update LED displays
	if (timer1Flag != 0) {
		displayTextOnLed(videoBuffer, LEDText, &column, &columnIndex,&LEDIndex, &runs,menu);
		timer1Flag = 0;
	}

	} // End of main while loop
} // End of main()
