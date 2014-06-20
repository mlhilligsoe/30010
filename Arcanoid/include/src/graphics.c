#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"
#include "ansi.h"
#include "timer.h"

void drawTopBar(struct Player player){
	fgcolor(8);

	gotoxy(1,1);
	printf("Lifes: %d", player.lifes);
	gotoxy(35,1);
	printf("Level: %d", player.level+1);
	gotoxy(66,1);
	printf("Points: %05d", player.points);
}

void drawEdges(){
	int i;
	fgcolor(8);

	gotoxy(0,2);
		printf("%c",220);
	for(i=0;i<78;i++){	// prints top 
		printf("%c",220);
		}
	printf("%c",220);

	for(i=3;i<24;i++){
		gotoxy(0,i);
			printf("%c",219); // prints left edge
		gotoxy(80,i);
			printf("%c",219); // prints right edge
		}
}

void drawLevel(struct Ball ball, struct Player player, struct Block blocks[]){
	
	int i;
	printf("ESC[?25l");
	bgcolor(0);
	fgcolor(15);
	clrscr();
	drawEdges();

	for(i=0;i<64;i++){	
		drawBlock(blocks[i]); // prints blocks
	}

	redrawPlayer((char)(player.x>>16),(char)(player.x>>16)); // prints player 

	redrawBall((char)(ball.x>>16),(char)(ball.y>>16),(char)(ball.x>>16),(char)(ball.y>>16));  // prints ball 
	drawTopBar(player);

}



void redrawPlayer(char x_old, char x_new){
	fgcolor(15);

	//erase player bar
	gotoxy(x_old-2, 23);
	printf("     ");
	// redraw player bar
	gotoxy(x_new-2, 23);
	printf("%c%c%c%c%c",223,223,223,223,223);
	gotoxy(0,0);
}

void redrawBall(char x_old, char y_old, char x_new, char y_new){
	fgcolor(15);
	gotoxy(x_old, y_old);
	printf(" ");
	gotoxy(x_new, y_new);
	printf("%c",184);
	gotoxy(0,0);	

	
}

// draws block - color depends on no. of lives.
void drawBlock(struct Block block){
	
	if(block.lifes >= 0){
		gotoxy(block.x, block.y);
	
		if(block.lifes == 0){
			fgcolor(0);
			bgcolor(0);
			printf("   ");
		}
		else if(block.lifes == 1){
			fgcolor(9);
			bgcolor(0);
			printf("%c%c%c",176,176,176);
		}
		else if(block.lifes == 2){
			fgcolor(10);
			bgcolor(0);
			printf("%c%c%c",177,177,177);
		}
		else if(block.lifes == 3) {
			fgcolor(11);
			bgcolor(0);
			printf("%c%c%c",178,178,178);
		}
		else{
			fgcolor(12);
			printf("%c%c%c", 219,219,219);
		}
	}	
	gotoxy(0,0);
	fgcolor(15);
	bgcolor(0);
}


