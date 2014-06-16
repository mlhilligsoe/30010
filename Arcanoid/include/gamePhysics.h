#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   

#include "struct.h"

#ifndef _GAMEPHYSICS_H_
#define _GAMEPHYSICS_H_

void updatePlayerPos(char input, struct Player* player);
void updateBallPos(struct Ball* ball);
void checkWallCollision(struct Ball* ball, struct Level* level, struct Player* player);
void checkPlayerCollision(struct Ball* ball, struct Player* player);
void checkBlockCollision(struct Ball* ball, struct Block* blocks);
void updatePosition(char input, struct Player* player, struct Ball* ball);
void checkCollision(struct Player* player, struct Ball* ball, struct Level* level);

#endif /*_GAMEPHYSICS_H_*/
