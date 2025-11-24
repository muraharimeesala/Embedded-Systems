//Write a C program to search all occurrences of a character in a given string
#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i=0,found=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	for(i=0;str[i]!='\0';i++){         // Removing new lines
		if(str[i]=='\n'){
			str[i]='\0';
			break;
		}
	}
	char ch;
	printf("Enter a character to search:");
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch){
		printf("character is found at position %d(index %d).\n",i,i+1);
		found=1;
		}
	}
	if(!found){
		printf("character %c is not found int string.",ch);
	}
}

