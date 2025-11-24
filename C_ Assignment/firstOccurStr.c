#include<stdio.h>
#include<string.h>
int main(){
	char str[100],ch;
	int i,pos=-1;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	printf("Enter character to search:");
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch){
			pos=i;
			break;
		}
	}
	if(pos!=-1){
		printf("First occurs character found at position %d.\n",pos);
	}
	else{
		printf("Not found in the string.\n");
	}
}
