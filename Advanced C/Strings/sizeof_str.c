#include<stdio.h>
#include<string.h>
int main(){
char name[12];
printf("Enter your name:");
scanf("%s",name);
int length=strlen(name);
printf("The size of string is:%d\n",length);
}

