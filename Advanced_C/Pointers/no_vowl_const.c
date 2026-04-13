#include<stdio.h>
#include<ctype.h>
int main(){
char name[100];
char *ptr=name;
int constt=0,vowl=0;
printf("Enter a string:");
scanf("%s",name);
while(*ptr!='\0'){
char ch=tolower(*ptr);
if((ch>='a' && ch<='z')){
if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
vowl++;
}
else{
constt++;
}
}
ptr++;
}
printf("No vowels:%d\n",vowl);
printf("No of consonants:%d\n",constt);
}

