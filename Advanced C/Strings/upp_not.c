#include<stdio.h>
#include<ctype.h>
int main(){
	char ch;
	printf("Enter a character:");
	scanf("%c",&ch);
	if(ch>='A' && ch<='Z'){
		printf("%c is a uppercase.\n",ch);
	}
	else{
		printf("%c is not a uppercase.\n",ch);
	}
}
