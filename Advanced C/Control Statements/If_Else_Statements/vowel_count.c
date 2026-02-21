#include<stdio.h>
#include<string.h>
int main(){
char str[100];
int i,count=0;
printf("Enter a string:");
fgets(str,sizeof(str),stdin);
for(i=0;i<str[i]!='\0';i++){
char ch=str[i];
if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
count++;
}
}
printf("No of vowel in the string:%d \n",count);
}



