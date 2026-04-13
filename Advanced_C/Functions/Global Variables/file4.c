#include <stdio.h>
extern int globalVar;
void modifyGlobalVar() {
    globalVar = 20;  // Modify the global variable
    printf("In file2.c, globalVar = %d\n", globalVar);
}

