
#ifndef _ANSI_H_
#define _ANSI_H_

#define ESC 0x1B

void fgcolor(int foreground);
void bgcolor(int  background);
void color(int foreground, int background);
void resetbgcolor();
void gotoxy(int x, int y);
void clrscr();
void clreol();
void underline(char on);
void blink(char on);
void reverse(char on);
void window(int x1, int y1, int x2, int y2, char* title, char style);
void rotate(struct TVector *v, long deg);
void initVector(struct TVector *v, long a, long b);

struct TVector{
long x,y;
};
#endif /* _ANSI_H_ */