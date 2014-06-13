#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines


char readkey(){

char cPFIN = PFIN;
char cPDIN = PDIN;

char btn0, btn1, btn2;

btn0 = (~cPFIN & 0x80) >> 7 ; // tilde is bitwise negation, ampersand is bitwise and, >> is right shifting, moving bit 7's value to bit 0. 
btn1 = (~cPFIN & 0x40) >> 5 ;
btn2 = (~cPDIN & 0x08) >> 1 ;

return (btn0 | btn1 | btn2); // char is 8 bit, the 3 functions is or'd together making 0000 0xxx as output.
}

