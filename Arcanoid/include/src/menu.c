#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "menu.h"
#include "struct.h"
#include "ansi.h"

void createMenu(char menu){
	
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
		break;
	case 2:
		// Draw Level Select Menu
		window(5, 3, 35, 8, "Level Select", 1);
		break;
	case 3:
		// Draw Pause Menu
		window(5, 3, 35, 8, "Pause", 1);
		break;
	case 4:
		// Draw GameWon Menu
		window(5, 3, 35, 8, "Game Won", 1);
		break;
	case 5:
		// Draw GameLost Menu
		window(5, 3, 35, 8, "Game Lost", 1);
		break;
	}
}

void menuInput(char input, char* selection, char* menu){
		switch (*menu) {
	case 1:
		// Main Menu
		gotoxy(8,5+(*selection)*2);
		printf(" ");
		
		if((input == 0x01) && (*selection < 1)){
			(*selection)++;
		}else if((input == 0x04) && (*selection > 0)){
			(*selection)--;
		}

		gotoxy(8,5+(*selection)*2);
		printf("*");
		break;
	case 2:
		// Draw Level Select Menu
		window(5, 3, 35, 8, "Level Select", 1);
		break;
	case 3:
		// Draw Pause Menu
		window(5, 3, 35, 8, "Pause", 1);
		break;
	case 4:
		// Draw GameWon Menu
		window(5, 3, 35, 8, "Game Won", 1);
		break;
	case 5:
		// Draw GameLost Menu
		window(5, 3, 35, 8, "Game Lost", 1);
		break;
	}
}
