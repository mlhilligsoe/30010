#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"
#include "ansi.h"

// Draws the top line with Lifes, level and points. Requires a player struct as argument.
void drawTopBar(struct Player player){
	fgcolor(15); // White foreground color

	// No need to delete first as all writes allways have same legth.
	gotoxy(1,1);
	printf("Lifes: %d", player.lifes);
	gotoxy(35,1);
	printf("Level: %d", player.level+1);
	gotoxy(66,1);
	printf("Points: %05d", player.points);

	gotoxy(0,0);
}

// Draws edges at the sides and the top of the level. No arguments required.
void drawEdges(){
	int i;
	fgcolor(15); // White foreground color

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

	gotoxy(0,0);
}

// Functionen that draws all elements of a level. Used at level initialization.
// Requires essentially all data as arguments: Ball struct, Player struct and Block struct array.
void drawLevel(struct Ball ball, struct Player player, struct Block blocks[]){
	
	int i;
	printf("ESC[?25l"); // Escape char should hide curser. Doesnt seem ti work.
	bgcolor(0);			// Sets the background to black.
	fgcolor(15);		// Sets the foreground to white.
	clrscr();			// Clears screen

	drawEdges();		// Draw Level edges

	for(i=0;i<64;i++){	
		drawBlock(blocks[i]); // Draw blocks
	}

	redrawPlayer((char)(player.x>>16),(char)(player.x>>16)); // Draw player

	redrawBall((char)(ball.x>>16),(char)(ball.y>>16),(char)(ball.x>>16),(char)(ball.y>>16));  // Draw ball

	drawTopBar(player); // Draw top bar

}

// First deletes player at old position and the redraws at new. Requires a old and new X-position. Y-position is hardcoded.
void redrawPlayer(char x_old, char x_new){
	fgcolor(15); // White foreground

	// Erase player slider
	gotoxy(x_old-2, 23);
	printf("     ");
	// Redraw player slider
	gotoxy(x_new-2, 23);
	printf("%c%c%c%c%c",223,223,223,223,223); // Solid blocks

	gotoxy(0,0);
}

// Deletes old ball and redraws at new position. Requires both old and new x and y positins.
void redrawBall(char x_old, char y_old, char x_new, char y_new){
	fgcolor(15); // White foreground

	// Delete at old position
	gotoxy(x_old, y_old);
	printf(" ");

	// Redraw at new position
	gotoxy(x_new, y_new);
	printf("%c",184);


	gotoxy(0,0);	
}

// Draws a block - color depends on no. of lives. Block structue required.
void drawBlock(struct Block block){
	
	// Test for lives. Blocks with lifes < 0 are ignored.
	if(block.lifes >= 0){
		gotoxy(block.x, block.y); // Go to block position
	
		if(block.lifes == 0){	// Delete block if it has no lifes left.
			fgcolor(0);
			printf("   ");
		}
		else if(block.lifes == 1){			// Rest of the if's draws a block with a specific color according to its lifes.
			fgcolor(9);
			printf("%c%c%c",176,176,176);
		}
		else if(block.lifes == 2){
			fgcolor(10);
			printf("%c%c%c",177,177,177);
		}
		else if(block.lifes == 3) {
			fgcolor(11);
			printf("%c%c%c",178,178,178);
		}
		else{
			fgcolor(12);
			printf("%c%c%c", 219,219,219);
		}
	}	

	gotoxy(0,0);
}
