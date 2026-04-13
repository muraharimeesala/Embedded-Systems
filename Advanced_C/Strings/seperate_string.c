#include<stdio.h>
#include<stdlib.h>
int main(){
char name[20];
int l=0;
printf("Enter your name:");
fgets(name,sizeof(name),stdin);
while(name[l]!='\0'){
printf("%c ",name[l]);
l++;
}
printf("\n");
}

