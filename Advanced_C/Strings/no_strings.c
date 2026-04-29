#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define str_size 100
int main(){
char name[str_size];
int i,word;
printf("Enter a string:");
fgets(name,sizeof(name),stdin);
i=0;
word=1;
while(name[i]!='\0'){
if(name[i]==' '|| name[i]=='\n'|| name[i]=='\t'){
word++;
}
i++;
}
printf("The no of string are:%d\n",word-1);
}
