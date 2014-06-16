#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>   
#include "struct.h"
updatePlayerPos(char input, struct Player* player){

}

updateBallPos(struct Ball* ball){
    
    char old_x = (char) (ball->x >> 16);
    char old_y = (char) (ball->y >> 16);
    ball->x = ball->x + ball->vx;
    ball->y = ball->y + ball->vy;
    char new_x = (char) (ball->x >>16);
    char new_y = (char) (ball->y >>16);
    
    redrawBall(old_x, old_y, new_x, new_y);
    
    
}

checkWallCollision(struct Ball* ball, struct Level* level){

}

checkPlayerCollision(struct Ball* ball, struct Player* player){

}

checkBlockCollosion(struct Ball* ball, struct Level* level){

}

updatePosition(char input, struct Player* player, struct Ball* ball){

}

checkCollision(struct Player* player, struct Ball* ball, struct Level* level){
}

setLevel(struct Player* player, struct Ball* ball, struct Level* level){

}
