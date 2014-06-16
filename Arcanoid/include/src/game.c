//#include <eZ8.h>             // special encore constants, macros and flash routines
//#include <sio.h>             // special encore serial i/o routines

#include "game.h"
#include "menu.h"
#include "struct.h"

void pause(char* menu, char* selection){
	*menu = 3;
	createMenu(*menu, selection);
}

void gameLost(struct Player* player, struct Level* level, char* menu, char* selection){
	*menu = 5;
	createMenu(*menu, selection);
}

void gameWon(struct Player* player, struct Level* level, struct Ball* ball, char* menu, char* selection){
	*menu = 4;
	createMenu(*menu, selection);
}

void setLevel(struct Player* player, struct Ball* ball, struct Level* level){

}
