#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"

void redrawPlayer(char x.old, char y.old, char x.new, char y.new);
void redrawBall(char x.old, char y.old, char x.new, char y.new);
void drawBlock(struct Block* block);
void drawEdges();
void drawLevel();