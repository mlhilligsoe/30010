#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>
#include "ansi.h"
#include "printFix.h"

void fgcolor(int foreground) {
	/*  Value      foreground     Value     foreground
	 ------------------------------------------------
	 0        Black            8       Dark Gray
	 1        Red              9       Light Red
	 2        Green           10       Light Green
	 3        Brown           11       Yellow
	 4        Blue            12       Light Blue
	 5        Purple          13       Light Purple
	 6        Cyan            14       Light Cyan
	 7        Light Gray      15       White
	 */
	int type = 22; // normal text
	if (foreground > 7) {
		type = 1; // bold text
		foreground -= 8;
	}
	printf("%c[%d;%dm", ESC, type, foreground + 30);
}

void bgcolor(int background) {
	/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
	 Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
	 The designers of HyperTerminal, however, preferred black text on white background, which is why
	 the colors are initially like that, but when the background color is first changed there is no
	 way comming back.
	 Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

	 Value      Color
	 ------------------
	 0        Black
	 1        Red
	 2        Green
	 3        Brown
	 4        Blue
	 5        Purple
	 6        Cyan
	 7        Gray
	 */
	printf("%c[%dm", ESC, background + 40);
}

void color(int foreground, int background) {
	// combination of fgcolor() and bgcolor() - uses less bandwidth
	int type = 22; // normal text
	if (foreground > 7) {
		type = 1; // bold text
		foreground -= 8;
	}
	printf("%c[%d;%d;%dm", ESC, type, foreground + 30, background + 40);
}

void resetbgcolor() {
	// gray on black text, no underline, no blink, no reverse
	printf("%c[m", ESC);
}

void gotoxy(int x, int y) {
	printf("%c[%d;%dH", ESC, y, x);
}

void clrscr() {
	printf("%c[2J", ESC);
}

void clreol() {
	printf("%c[K", ESC);
}

void underline(char on) {
	if (on == 1) {
		printf("%c[04m", ESC);
	} else {
		printf("%c[24m", ESC);
	}
}

void blink(char on) {
	if (on == 1) {
		printf("%c[05m", ESC);
	} else {
		printf("%c[25m", ESC);
	}
}

void reverse(char on) {
	if (on == 1) {
		printf("%c[07m", ESC);
	} else {
		printf("%c[27m", ESC);
	}
}

void window(int x1, int y1, int x2, int y2, char* title, char style) {
	int i, title_len;
	char tl, tr, bl, br, hl, vl, lt, rt;

	if (style == 1) {
		tl = 218;
		tr = 191;
		bl = 192;
		br = 217;
		hl = 196;
		vl = 179;
		lt = 180;
		rt = 195;
	} else {
		tl = 201;
		tr = 187;
		bl = 200;
		br = 188;
		hl = 205;
		vl = 186;
		lt = 185;
		rt = 204;
	}

	title_len = strlen(title);

	/* Draw top/title */
	gotoxy(x1, y1);
	printf("%c%c", tl, lt);
	reverse(1);
	printf(" %s ", title);
	if (style == 1) {
		printf("%*c", x2 - x1 - 5 - title_len, 0);
		reverse(0);
		printf("%c%c", rt, tr);
	} else {
		reverse(0);
		printf("%c", rt);
		for (i = x1 + 4 + title_len; i < x2 - 1; i++)
			printf("%c", hl);
		printf("%c", tr);
	}

	/* Draw sides */
	for (i = (y1 + 1); i < y2; i++) {
		gotoxy(x1, i);
		printf("%c", vl);
		gotoxy(x2, i);
		printf("%c", vl);
	}

	/* Draw bottom */
	gotoxy(x1, y2);
	printf("%c", bl);
	for (i = x1 + 1; i < x2; i++) {
		printf("%c", hl);
	}
	printf("%c", br);
}

