/*
custom library (create a new library)
<> are for standard C libraries the compiler knows where they are
"full path to the.h file " when the library is on the same file of the program there is no need for the full path just the name of the file 
#include "filrname.h"

#ifndef NAME: if not defined, going t check that i didnot included such a library befor and if this is true then #define NAME
prototypes
#endif : this called include guard 

*/
/* to compile:
1.c file the gcc compile it to .exe
2.c or more
gcc each.c then .o
gcc all.o then .exe
*/
/*
gcc -c 1.c 
gcc -c 2.c
gcc 1.o 2.o -o name.exe
name.exe */ 
/*partial compilation*/
#include "mymath.h" 