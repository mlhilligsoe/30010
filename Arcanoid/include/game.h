#ifndef _GAME_H_
#define _GAME_H_

#include "struct.h"

void pause(char* menu, char* selection);
void boss(char* menu, char* selection);
void gameLost(struct Player* player, struct Level* level, char* menu, char* selection);
void gameWon(struct Player* player, struct Level* level, struct Ball* ball, char* menu, char* selection);
void initLevel(struct Player* player, struct Ball* ball, struct Level* level);
void resetLevel(struct Player* player, struct Ball* ball, struct Level* level);
void nextLevel(struct Player* player, struct Ball* ball, struct Level* level);
#endif /* _GAME_H_ */
