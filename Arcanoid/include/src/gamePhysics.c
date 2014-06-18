#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"
#include "gamephysics.h"
#include "game.h"
#include "ansi.h"

void updatePlayerPos(char input, struct Player* player){
	char old_x;
 	old_x = (char)(player->x >> 16);

	if(input == 0x01 && (player->x < (77 << 16))){//boundries for player
		player->x = player->x + (1 << 16); // multiplier for player cursor
		redrawPlayer(old_x,(char)(player->x >> 16) );
	}
	else if (input == 0x04 && (player->x > (4 << 16))){ //boundries for player
		player->x = player->x - (1 << 16); // multiplier for player cursor
		redrawPlayer(old_x,(char)(player->x >> 16) );
	}
}

void updateBallPos(struct Ball* ball, struct Player* player){
	char old_x;
	char old_y;
	char new_x;
	char new_y;

    old_x = (char)(ball->x >> 16);
    old_y = (char)(ball->y >> 16);

    ball->x = ball->x + ball->vx;
    ball->y = ball->y + ball->vy;
    
	new_x = (char)(ball->x >> 16);
    new_y = (char)(ball->y >> 16);
    
    if(old_x != new_x || old_y != new_y){
    	redrawBall(old_x, old_y, new_x, new_y);
    }
    
}

void checkWallCollision(struct Ball* ball, struct Level* level, struct Player* player){

	// Check for Left Wall collisions
	if( ball->x  < (2 << 16) + 16383){
		ball->vx = -ball->vx;
	}
	// Check for Right Wall collisions
	else if ( ball->x > (79 << 16) - 16383 ){
		ball->vx = -ball->vx;
	}

	// Check for Top Wall collisions
	if( ball->y < (3 << 16) + 16383 ){
		ball->vy = -ball->vy;
	}
	else if ( (char)(ball->y >> 16) > 22 ){
		// Player Looses a Life,
		resetLevel(player, ball, level);
		drawLevel(*ball, *player, level->blocks);
		player->lifes = player->lifes - 1;
		drawTopBar(*player);
	}

}

void checkPlayerCollision(struct Ball* ball, struct Player* player){
char check = 0;
	if(ball->y > (23 << 16)-16383) {
		if( (ball->x >> 16) >= (player->x >> 16) - 2 && (ball->x >> 16) < (player->x >> 16) - 1){
				ball->vy = -ball->vy;
				check =1;
			if(ball->vx >=0){
				ball->vx =-ball->vx;
				}
			}
		if( (ball->x >> 16) >= (player->x >> 16) - 1 && (ball->x >> 16) < (player->x >> 16) ){
				ball->vy = -ball->vy;
				check =1;}
		if( (ball->x >> 16) >= (player->x >> 16) && (ball->x >> 16) < (player->x >> 16) + 1){
				ball->vy = -ball->vy;
				check =1;}
		if( (ball->x >> 16) >= (player->x >> 16) + 1 && (ball->x >> 16) < (player->x >> 16) + 2){
				ball->vy = -ball->vy;
				check =1;}
		if( (ball->x >> 16) >= (player->x >> 16) + 2 && (ball->x >> 16) < (player->x >> 16) + 3){
				ball->vy = -ball->vy;
				check =1;
				if(ball->vx <=0){
				ball->vx =-ball->vx;
				}}
		if( check == 1){
				ball->y = (23 << 16) - 16383;
				player->points +=1;
				drawTopBar(*player);
				check = 0 ; }
		
	}
}

void checkBlockCollision(struct Ball* ball, struct Level* level, struct Player* player){
	int i;	
	struct Block* blocks = level->blocks;	

	for(i = 0; i < 64; i++){
		if(blocks[i].lifes > 0){
			if( (ball->x >  (long)blocks[i].x << 16) && (ball->y >  (long)blocks[i].y << 16) && (ball->x < ((long)blocks[i].x + 3) << 16) && (ball->y <  ((long)blocks[i].y + 1) << 16) ){
				blocks[i].lifes--;
				drawBlock(blocks[i]);
				level->lifes--;
				
				ball->vx = -ball->vx;
				ball->vy = -ball->vy;

				player->points++;
				drawTopBar(*player);
			}
		}
	}
}

void updatePositions(char input, struct Player* player, struct Ball* ball){
	updatePlayerPos(input, player);
	updateBallPos(ball, player);
}

void testForCollisions(struct Player* player, struct Ball* ball, struct Level* level){
	checkWallCollision(ball, level, player);
	checkPlayerCollision(ball, player);
	checkBlockCollision(ball, level, player);
}


