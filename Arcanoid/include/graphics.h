#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"

void redrawPlayer(char x_old, char y_old, char x_new, char y_new);
void redrawBall(char x_old, char y_old, char x_new, char y_new);
void drawBlock(struct Block block);
void drawEdges();
void drawLevel(struct Ball ball, struct Player player, struct Block blocks[]);
