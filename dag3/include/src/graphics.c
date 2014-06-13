#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"


void redrawPlayer(char x.old, char y.old, char x.new, char y.new){
	//erase player bar
	gotoxy(x.old, y.old);
	printf("     ");
	// redraw player bar
	gotoxy(x.new, y.new);
	printf("<===>");

}

void redrawBall(char x.old, char y.old, char x.new, char y.new){
gotoxy(x.old, y.old);
printf(" ");
gotoxy(x.new, y.new);
printf("O");
}

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