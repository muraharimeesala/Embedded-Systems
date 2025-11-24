#include<stdio.h>
int main(){
int *intptr;
float *floatptr;
char *charptr;
void *voidptr;
printf("Size of INT pointer:%zu bytes\n",sizeof(intptr));
printf("Size of FLOAT pointer:%zu bytes\n",sizeof(floatptr));
printf("Size of CHAR pointer:%zu bytes\n",sizeof(charptr));
printf("Size of VOID pointer:%zu bytes\n",sizeof(voidptr));
}

