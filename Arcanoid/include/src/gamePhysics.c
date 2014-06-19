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
	
change in x:
			cos(angle)*speed
 ball->x = ball->x + (long)(cos(ball->angle))*(long)(ball->speed);
	change in y:
			sin(angle)*speed
 ball->y = ball->y + (long)(sin(ball->angle))*(long)(ball->speed);


//    ball->x = ball->x + ball->vx; old way - not using speed/angle
//    ball->y = ball->y + ball->vy; old way - not using speed/angle

    
	new_x = (char)(ball->x >> 16);
    new_y = (char)(ball->y >> 16);
    
    if(old_x != new_x || old_y != new_y){
    	redrawBall(old_x, old_y, new_x, new_y);
    }
    
}

void checkWallCollision(struct Ball* ball, struct Level* level, struct Player* player){

	// Check for Left Wall collisions
	if( ball->x  < (2 << 16) + 16383){
<<<<<<< HEAD
		//ball->vx = -ball->vx;
		ball->angle = 256 - ball->angle;
				//drawEdges();
	}
	// Check for Right Wall collisions
	else if ( ball->x > (79 << 16) - 16383 ){
		//ball->vx = -ball->vx;
		ball->angle = 256 - ball->angle;
		//drawEdges();
=======
		ball->vx = -ball->vx;
	}
	// Check for Right Wall collisions
	else if ( ball->x > (79 << 16) - 16383 ){
		ball->vx = -ball->vx;
>>>>>>> ed90d149cefab07dae6154c043089b3b83f3285c
	}

	// Check for Top Wall collisions
	if( ball->y < (3 << 16) + 16383 ){
<<<<<<< HEAD
		//ball->vy = -ball->vy;
		ball->angle = - ball->angle;
		//drawEdges();
=======
		ball->vy = -ball->vy;
>>>>>>> ed90d149cefab07dae6154c043089b3b83f3285c
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
				//ball->vy = -ball->vy;
			ball->angle = - ball->angle;
				check =1;
			if((ball->angle % 512) >=384){
				//ball->vx =-ball->vx;
				ball->angle = - ball->angle;

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
	char hit;
	struct Block* blocks = level->blocks;	

	for(i = 0; i < 64; i++){
		if(blocks[i].lifes > 0){
			hit = 0;

			// Check if ball hits from either side
			if(    (	ball->x > ( (long)blocks[i].x << 16 ) - 16383 			) 
				&& (	ball->y > ( (long)blocks[i].y << 16 )					) 
				&& (	ball->x < ( ((long)blocks[i].x + 3) << 16 ) + 16383		) 
				&& (	ball->y < ( ((long)blocks[i].y + 1) << 16 )				) 
			){
				
				ball->vx = -ball->vx;
				ball->x += ball->vx;
				hit = 1;
			}
			
			// Check if ball hits from top or bottom
			if(    (	ball->x > ( (long)blocks[i].x << 16 )					) 
				&& (	ball->y > ( (long)blocks[i].y << 16 ) - 16383 			) 
				&& (	ball->x < ( ((long)blocks[i].x + 3) << 16 ) 			)
				&& (	ball->y < ( ((long)blocks[i].y + 1) << 16 ) + 16383 	)
			){
				ball->vy = -ball->vy;
				ball->y += ball->vy;
				hit = 1;
			}

			if( hit == 1){
				blocks[i].lifes--;
				drawBlock(blocks[i]);
				level->lifes--;
				
				player->points++;
				drawTopBar(*player);
			}

		}
	} // end of for  loop
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


