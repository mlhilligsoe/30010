#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include "game.h"
#include "menu.h"
#include "struct.h"

void pause(char* menu){
	*menu = 3;
}

void gameLost(struct Player* player, struct Level* level, char* menu){
	*menu = 5;
	createMenu(menu);
}

void gameWon(struct Player* player, struct Level* level, struct Ball* ball, char* menu){
	*menu = 4;
	createMenu(menu);
}