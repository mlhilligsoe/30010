#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "menu.h"
#include "struct.h"
#include "ansi.h"
#include "graphics.h"
#include "game.h"

void createMenu(char menu, char* selection){
	int i;
	
	// Set color scheme
	bgcolor(0);
	fgcolor(15);
	
	// Clear screen
	clrscr();
	
	switch (menu) {
	case 1:
		// Draw Main Menu
		window(5, 3, 35, 9, "Main Menu", 1);
		gotoxy(8,5);
		printf("*");
		gotoxy(10,5);
		printf("Start Game");
		gotoxy(10,7);
		printf("Select Level");

		*selection = 0;
		break;
	case 2:
		// Draw Level Select Menu
		window(5, 3, 35, 17, "Level Select", 1);
		gotoxy(8,5);
		printf("*");
		gotoxy(10,5);
		printf("Here We Go!");
		gotoxy(10,7);
		printf("The Beginning");
		gotoxy(10,9);
		printf("The Middle");
		gotoxy(10,11);
		printf("The End");
		gotoxy(10,13);
		printf("!oG eW ereH");
		gotoxy(10,15);
		printf("..Back to Main");

		*selection = 0;
		break;
	case 3:
		// Draw Pause Menu
		window(5, 3, 35, 9, "Pause", 1);
		gotoxy(8,5);
		printf("*");
		gotoxy(10,5);
		printf("Continue");
		gotoxy(10,7);
		printf("Quit");

		*selection = 0;
		break;
	case 4:
		// Draw GameWon Menu
		window(5, 3, 35, 9, "Level Completed", 1);
		gotoxy(10,5);
		printf("Your cleared the level!");
		gotoxy(8,7);
		printf("*");
		gotoxy(10,7);
		printf("Continue to next level");

		*selection = 1;
		break;
	case 5:
		// Draw GameLost Menu
		window(5, 3, 35, 9, "Game Lost", 1);
		gotoxy(10,5);
		printf("Your lost all your lifes!");
		gotoxy(8,7);
		printf("*");
		gotoxy(10,7);
		printf("Continue to Menu");

		*selection = 1;
		break;
	case 6:
		// Draw GameLost Menu
		window(5, 3, 35, 9, "Game Won", 1);
		gotoxy(10,5);
		printf("Congratulations, you completed the game!");
		gotoxy(8,7);
		printf("*");
		gotoxy(10,7);
		printf("Continue to Menu");

		*selection = 1;
		break;
	case 7:
		// Draw Boss Menu
		window(5, 3, 67, 19, "Important Work", 1);
		gotoxy(8,5);
		printf("*  Dear Colleague,");
		gotoxy(10,6);
		printf("This message is very important, please read it carefully");
		gotoxy(10,7);
		printf("You should work more and work harder.");
		gotoxy(10,8);
		printf("It is important to work hard and deserve your paycheck.");
		gotoxy(10,9);
		printf("Make sure you do this.");
		gotoxy(10,11);
		printf("Best Regards, Your Colleague.");

		*selection = 0;
		break;
	}
}

void menuInput(int input, char* selection, char* menu, struct Level* level, struct Player* player, struct Ball* ball){
	switch (*menu) {
	case 1:
		// Main Menu
		moveCursor(input ,selection, 0, 1);

		//Select entry
		if(input == 2 && *selection == 0){
			player->level = 0;
			initLevel(player, ball, level);
			drawLevel(*ball, *player, level->blocks);
			*menu = 0;
		}
		else if(input == 2 && *selection == 1){
			*menu = 2;
			createMenu(*menu, selection);
		}
		break;
	case 2:
		// Level Select Menu
		moveCursor(input, selection, 0, 5);

		//Select entry
		if(input == 2 && *selection < 5){
			player->level = *selection;
			initLevel(player, ball, level);
			drawLevel(*ball, *player, level->blocks);
			*menu = 0;
		}
		else if(input == 2 && *selection == 5){
			*menu = 1;
			createMenu(*menu, selection);
		}
		break;
	case 3:
		// Pause Menu
		moveCursor(input, selection, 0, 1);

		//Select entry
		if(input == 2 && *selection == 0){
			drawLevel(*ball, *player, level->blocks);
			*menu = 0;
		}
		else if(input == 2 && *selection == 1){
			*menu = 1;
			createMenu(*menu, selection);
		}
		break;
	case 4:
		// Level Completed Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input == 2 && *selection == 1){
			nextLevel(player, ball, level);
			drawLevel(*ball, *player, level->blocks);
			*menu = 0;
		}
		break;
	case 5:
		// GameLost Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input == 2 && *selection == 1){
			*menu = 1;
			createMenu(*menu, selection);
		}
		break;
	case 6:
		// GameWon Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input == 2 && *selection == 1){
			*menu = 1;
			createMenu(*menu, selection);
		}
		break;
	case 7:
		// Boss Menu
		moveCursor(input, selection, 0, 0);

		//Select entry
		if(input == 2 && *selection == 0){
			drawLevel(*ball, *player, level->blocks);
			*menu = 0;
		}
		break;

	}
}

void moveCursor(int input, char* selection, char min, char max){
	gotoxy(8,5+(*selection)*2);
	printf(" ");

	if((input  == 1) && (*selection < max)){
		(*selection)++;
	}else if((input == 4) && (*selection > min)){
		(*selection)--;
	}

	gotoxy(8,5+(*selection)*2);
	printf("*");
}
