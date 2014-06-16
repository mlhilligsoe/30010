#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
#include "graphics.h"
#include "gamephysics.h"

void updatePlayerPos(char input, struct Player* player){

}

void updateBallPos(struct Ball* ball){
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

	// Check for X-axis collisions
	if(ball->x < 1){
		ball->vx = -ball->vx;
		drawEdges();
	}
	else if (ball->x > 78){
		ball->vx = -ball->vx;
		drawEdges();
	}

	// Check for X-axis collisions
	if(ball->y < 2){
		ball->vy = -ball->vy;
		drawEdges();
	}
	else if (ball->y > 24){
		// Player Looses a Life,
		//setLevel();
		//drawLevel();
		player->lifes -= 1;
	}

}

void checkPlayerCollision(struct Ball* ball, struct Player* player){
	if(ball->y > 23){
		if(ball->x >= player->x - 2 || ball->x < player->x - 1)
			ball->vy = -ball->vy;
		if(ball->x >= player->x - 1 || ball->x < player->x )
				ball->vy = -ball->vy;
		if(ball->x >= player->x || ball->x < player->x + 1)
				ball->vy = -ball->vy;
		if(ball->x >= player->x + 1 || ball->x < player->x + 2)
				ball->vy = -ball->vy;
		if(ball->x >= player->x + 2 || ball->x < player->x + 3)
				ball->vy = -ball->vy;
	}
}

void checkBlockCollision(struct Ball* ball, struct Block* blocks){

}

void updatePosition(char input, struct Player* player, struct Ball* ball){
	updatePlayerPos(input, player);
	updateBallPos(ball);
}

void checkCollision(struct Player* player, struct Ball* ball, struct Level* level){
	checkWallCollision(ball, level, player);
	checkPlayerCollision(ball, player);
	checkBlockCollision(ball, level->blocks);
}


