// write a program to find given char hexa digit or not 
#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	printf("Enter a character:");
	scanf("%c",&ch);
	if((ch>='0' && ch<='9')||(ch>='a' && ch<='f')||(ch>='A' && ch<='F')){
		printf("%c is a hexadecimal digit.\n",ch);
	}
	else{
		printf("%c is not a hexadecimal digit.\n",ch);
	}
}
