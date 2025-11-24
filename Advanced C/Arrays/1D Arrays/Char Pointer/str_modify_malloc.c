#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
char *ptr=malloc(100);
strcpy(ptr,"Linux");
printf("Before string modification:\n%s\n",ptr);
printf("Address of string:\n%p\n",&ptr);
strcpy(ptr,"System");
printf("After string modification:\n%s\n",ptr);
printf("Address of modify string:\n%p\n",&ptr);
free(ptr);
}

