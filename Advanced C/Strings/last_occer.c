#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i=0,last=-1;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	for(i=0;str[i]!='\0';i++){
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
			last=i;
		}
	}
	if(last!=-1){
		printf("character %c is found at index %d.",ch,last);
	}
	else{
		printf("character %c is not found in string.",ch);
	}
}

