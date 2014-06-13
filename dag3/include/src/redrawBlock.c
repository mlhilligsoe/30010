#include <eZ8.h>
#include <sio.h>
#include "struct.h"
void redrawBlock(struct Block* block){
gotoxy(block.x, block.y);
	if(block.lifes == 0){
		fgcolor(0);
		printf("   ");
		}
	else if(block.lifes == 1){
		fgcolor(1);
		printf("###");
	}
	else if(block.lifes == 2){
		fgcolor(11);
		printf("###");
	}
	else if(block.lifes == 3) {
		fgcolor(2);
		printf("###");
	}
	else {
		fgcolor(4);
		printf("###");
		
	}
	fgcolor(0);
}
