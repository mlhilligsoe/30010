
#ifndef _STRUCT_H_
#define _STRUCT_H_


struct TVector{
long x,y;
};

void initVector(struct TVector *v, long a, long b);


struct Ball{
long x;
long y;
long vx;
long vy;
};

struct Player{
long x;
long y;
int points;
char lifes;
char level;
};

struct Block{
char lifes;
char x;
char y;
};

struct Level{
struct Block blocks[128];
int lifes;
char wall[4];
};


#endif /*_STRUCT_H_*/
