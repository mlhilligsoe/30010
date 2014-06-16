#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "menu.h"
#include "struct.h"
#include "ansi.h"

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
		window(5, 3, 35, 7, "Pause", 1);
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
	}
}

void menuInput(char input, char* selection, char* menu, struct Level* level, struct Player* player, struct Ball* ball){
	switch (*menu) {
	case 1:
		// Main Menu
		moveCursor(input, selection, 0, 1);

		//Select entry
		if(input & 0x07 == 0x02 && *selection == 0){
			player->level = *selection;
			setLevel(level, player, ball);
			drawLevel(ball, player, level->blocks);
			*menu = 0;
		}
		else if(input & 0x07 == 0x02 && *selection == 1){
			*menu = 2;
			createMenu(menu, selection);
		}
		break;
	case 2:
		// Level Select Menu
		moveCursor(input, selection, 0, 5);

		//Select entry
		if(input & 0x07 == 0x02 && *selection < 5){
			player->level = *selection;
			setLevel(level, player, ball);
			drawLevel(ball, player, level->blocks);
			*menu = 0;
		}
		else if(input & 0x07 == 0x02 && *selection == 5){
			*menu = 1;
			createMenu(menu, selection);
		}
		break;
	case 3:
		// Pause Menu
		moveCursor(input, selection, 0, 1);

		//Select entry
		if(input & 0x07 == 0x02 && *selection == 0){
			drawLevel(ball, player, level->blocks);
			*menu = 0;
		}
		else if(input & 0x07 == 0x02 && *selection == 1){
			*menu = 1;
			createMenu(menu, selection);
		}
		break;
	case 4:
		// Level Completed Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input & 0x07 == 0x02 && *selection == 1){
			player->level = player->level + 1;
			setLevel(level, player, ball);
			drawLevel(ball, player, level->blocks);
			*menu = 0;
		}
		break;
	case 5:
		// GameLost Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input & 0x07 == 0x02 && *selection == 1){
			*menu = 1;
			createMenu(menu, selection);
		}
		break;
	case 5:
		// GameWon Menu
		moveCursor(input, selection, 1, 1);

		//Select entry
		if(input & 0x07 == 0x02 && *selection == 1){
			*menu = 1;
			createMenu(menu, selection);
		}
		break;
	}
}

void moveCursor(char input, char* selection, char min, char max){
	gotoxy(8,5+(*selection)*2);
	printf(" ");

	if((input & 0x07 == 0x01) && (*selection < max)){
		(*selection)++;
	}else if((input & 0x07 == 0x04) && (*selection > min)){
		(*selection)--;
	}

	gotoxy(8,5+(*selection)*2);
	printf("*");
}
