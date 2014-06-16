#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"

void drawEdges(){
	gotoxy(0,1);
		printf("%c",218);
	for(i=0;i<78;i++){	// prints top 
		printf("%c",196);
		}
	printf("%c",191);

	for(i=2;i<24;i++){
		gotoxy(0,i);
			printf("%c",179); // prints left edge
		gotoxy(79,i);
			printf("%c",179); // prints right edge
		}
}

void drawLevel(struct Ball ball, struct Player player, struct Block blocks[]){
	clrscr();
	drawEdges();

	for(i=0;i<(sizeof(blocks)/sizeof(blocks[0]));i++){	
		drawBlock(blocks[i]); // prints blocks
		}

	redrawPlayer(player.x,player.y,player.x,player.y); // prints player bar at 10,23

	redrawBall(ball.x,ball.y,ball.x,ball.y);  // prints ball at 10,10
}



void redrawPlayer(char x_old, char y_old, char x_new, char y_new){
	//erase player bar
	gotoxy(x_old, y_old);
	printf("     ");
	// redraw player bar
	gotoxy(x_new, y_new);
	printf("<===>");

}

void redrawBall(char x_old, char y_old, char x_new, char y_new){
gotoxy(x_old, y_old);
printf(" ");
gotoxy(x_new, y_new);
printf("O");
}

// draws block - color depends on no. of lives.
void drawBlock(struct Block block){
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


