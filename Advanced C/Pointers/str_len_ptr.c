#include<stdio.h>
int strLen(char *str){
	char *ptr=str;
	int len=0;
	while(*ptr!='\0'){
	len++;
	ptr++;
	}
	return len;
}
int main(){
	char str[100];
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	char *newline=str;
	while(*newline!='\0'){
		if(*newline=='\n'){
		*newline='\0';
		break;
		}
		newline++;
	}
	int Length=strLen(str);
	printf("Length of the string:%d\n",Length);
}

