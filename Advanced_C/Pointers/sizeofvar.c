#include<stdio.h>
int main(){
int a=10;
float b=1.25;
char c='A';
int *intptr;
float *floatptr;
char *charptr;
printf("size of pointer:%zu\n",sizeof(intptr));
printf("size of int pointer:%zu\n",sizeof(*intptr));
printf("size of pointer:%zu\n",sizeof(floatptr));
printf("size of float pointer:%zu\n",sizeof(*floatptr));
printf("size of pointer:%zu\n",sizeof(charptr));
printf("size of char pointer:%zu\n",sizeof(*charptr));
}
