#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h> 
#include "printFix.h"      

void printFix(long i) {
// prints a signed 16.16 fixed point number
if ((i & 0x80000000) != 0) { // handle negative numbers
printf("-");
i = ~i+1;
}
printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
// max 4 digits otherwise we get overflow
}

long expand(long i) {
// converts an 18.14 to a 16.16
return i << 2;
}


