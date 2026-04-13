#include<stdio.h>
int main(){
	char str[100];
	char *ptr=str;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	printf("Individual characters:\n");
	while(*ptr!='\0'){
		printf("%c",*ptr);
		ptr++;
	}
}




