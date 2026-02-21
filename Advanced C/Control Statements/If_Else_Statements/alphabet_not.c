#include<stdio.h>
int main(){
char ch;
printf("Enter a character:");
scanf("%c",&ch);
if(ch>='A' && ch<='Z' || ch>='a' && ch<='z'){
printf("%c is Alphabet\n",ch);
}
else{
printf("%c is Not Alphabet\n");
}
}
