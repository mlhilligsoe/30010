#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"


#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_


void drawTopBar(struct Player player);
void redrawPlayer(char x_old, char x_new);
void redrawBall(char x_old, char y_old, char x_new, char y_new);
void drawBlock(struct Block block);
void drawEdges();
void drawLevel(struct Ball ball, struct Player player, struct Block blocks[]);

#endif /*_GRAPHICS_H_*/
