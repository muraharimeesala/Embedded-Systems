#include<stdio.h>
#include<stdlib.h>
int main(){
char name[20];
int len=0;
printf("Enter your name:");
scanf("%s",name);
while(name[len]!='\0'){
len++;
}
printf("The length of the string is:%d",len);
}
