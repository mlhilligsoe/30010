#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"


void updatePlayerPos(char input, struct Player* player){

}

void updateBallPos(struct Ball* ball){

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
		player.lifes -= 1;
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

void checkBlockCollosion(struct Ball* ball, struct Level* level){

}

void updatePosition(char input, struct Player* player, struct Ball* ball){
	updatePlayerPos(input, player);
	updateBallPos(ball);
}

void checkCollision(struct Player* player, struct Ball* ball, struct Level* level){
	checkWallCollision(ball, level, player);
	checkPlayerCollision(ball, player);
	checkBlockCollision(ball, &(level->blocks));
}


