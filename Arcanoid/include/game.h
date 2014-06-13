#ifndef _GAME_H_
#define _GAME_H_

#include "struct.h"

void pause(char* menu);
void gameLost(struct Player* player, struct Level* level, char* menu);
void gameWon(struct Player* player, struct Level* level, struct Ball* ball, char* menu);

#endif /* _GAME_H_ */