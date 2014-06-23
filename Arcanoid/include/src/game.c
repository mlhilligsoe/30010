#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <stdlib.h>

#include "game.h"
#include "menu.h"
#include "struct.h"
#include "level.h"
#include "ansi.h"

void pause(char* menu, char* selection) {
	*menu = 3;
	createMenu(*menu, selection);
}
void boss(char* menu, char* selection) {
	*menu = 7;
	createMenu(*menu, selection);
}

void gameLost(struct Player* player, struct Level* level, char* menu,
		char* selection) {

	*menu = 5;
	createMenu(*menu, selection);
}

void gameWon(struct Player* player, struct Level* level, struct Ball* ball,
		char* menu, char* selection) {
	player->level++;
	*menu = 4;
	createMenu(*menu, selection);
}

void initLevel(struct Player* player, struct Ball* ball, struct Level* level) {
	int i;

	player->y = 23 << 16;
	player->lifes = 3;
	player->points = 0;

	ball->x = 40 << 16;
	ball->y = 18 << 16;
	ball->angle = rand() % 128 + 320;
	ball->speed = 8000 + 1500 * player->level;

	level->lifes = 0;
	for (i = 0; i < 64; i++) {
		level->blocks[i] = LEVELBLOCKS[player->level][i];

		if (level->blocks[i].lifes > 0) {
			level->lifes += level->blocks[i].lifes;
		}
	}

}

void resetLevel(struct Player* player, struct Ball* ball, struct Level* level) {

	ball->x = 40 << 16;
	ball->y = 18 << 16;
	ball->angle = rand() % 128 + 320;
	ball->speed = 8000 + 2000 * player->level;

}

void nextLevel(struct Player* player, struct Ball* ball, struct Level* level) {
	int i;

	ball->x = 40 << 16;
	ball->y = 18 << 16;
	ball->angle = rand() % 128 + 320;
	ball->speed = 8000 + 2000 * player->level;

	level->lifes = 0;
	for (i = 0; i < 64; i++) {
		level->blocks[i] = LEVELBLOCKS[player->level][i];

		if (level->blocks[i].lifes > 0) {
			level->lifes += level->blocks[i].lifes;
		}

	}

}
