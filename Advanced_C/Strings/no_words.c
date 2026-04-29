#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
char str[100];
int i,wordcount=0,inword=0;
printf("Enter a string:");
fgets(str,sizeof(str),stdin);
while(str[i]!='\0'){
if(isspace(str[i])||str[i]=='\n'){
inword=0;
}
else if(inword==0){
inword=1;
wordcount++;
}
i++;
}
printf("The no words count in the string:%d\n",wordcount);
}

