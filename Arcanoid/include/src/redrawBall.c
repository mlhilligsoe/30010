#include <eZ8.h>
#include <sio.h>

void redrawBall(char x.old, char y.old, char x.new, char y.new){
gotoxy(x.old, y.old);
printf(" ");
gotoxy(x.new, y.new);
printf("O");
}
