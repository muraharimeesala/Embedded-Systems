// write a program for first occurrence of a given character in a string with another character.
#include<stdio.h>
#include<string.h>
int main(){
	char str[100],ch,newCh;
	int i,found=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	printf("Enter character to replace:");
	scanf("%c",&ch);
	printf("Enter new character:");
	scanf("\n%c",&newCh);
	for(i=0;str[i]!='\0';i++){
		if(str[i]==ch){
			str[i]=newCh;
			found=1;
			break;
		}
	}
	if(found){
		printf("String after replcing the new character:%s\n",str);
	}
	else{
		printf("Character %c is not found int the string.\n",ch);
	}
}
