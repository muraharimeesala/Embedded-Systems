#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
char str[100];
int i=0,word=0;
printf("Enter a string:");
fgets(str,sizeof(str),stdin);
while(str[i]!='\0'){
while(str[i]==' '){
i++;
}
if(str[i]!='\0'){
word++;
while(str[i]!=' ' && str[i]!='\0'){
i++;
}
}
}
printf("No of words:%d\n",word);
}

