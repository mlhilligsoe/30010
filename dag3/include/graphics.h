#include <eZ8_h>             // special encore constants, macros and flash routines
#include <sio_h>   
#include "struct_h"

void redrawPlayer(char x_old, char y_old, char x_new, char y_new);
void redrawBall(char x_old, char y_old, char x_new, char y_new);
void drawBlock(struct Block* block);
void drawEdges();
void drawLevel();