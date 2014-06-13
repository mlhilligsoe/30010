#include <eZ8.h>
#include <sio.h>

void redrawPlayer(char x.old, char y.old, char x.new, char y.new){
	//erase player bar
	gotoxy(x.old, y.old);
	printf("     ");
	// redraw player bar
	gotoxy(x.new, y.new);
	printf("<===>");

}


