#include<stdio.h>
int main(){
char ch;
printf("Enter a character:");
scanf("%c",&ch);
if(ch>='A' && ch<='Z')
printf("%c is Uppercase\n",ch);
else
printf("%c is Lowercase\n",ch);
}
