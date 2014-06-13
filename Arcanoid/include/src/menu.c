//#include <eZ8.h>             // special encore constants, macros and flash routines
//#include <sio.h>             // special encore serial i/o routines

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
		window(5, 3, 35, 8, "Main Menu", 1);
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
