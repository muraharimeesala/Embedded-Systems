#include<stdio.h>
#include<string.h>
int main(){
char str[100];
int i,length=0;
printf("Enter a string:");
fgets(str,sizeof(str),stdin);
for(i=0;i<str[i]!='\0';i++){
if(str[i]=='\n')
break;
length++;
}
printf("Length of the string is:%d\n",length);
}

