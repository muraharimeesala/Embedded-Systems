#include<stdio.h>
#include<string.h>
int main(){
	char src[100],ch;
	printf("Enter a string:");
	fgets(src,sizeof(src),stdin);
	src[strcspn(src,"\n")]='\0';
	printf("Enter character to search:");
	scanf("%c",&ch);
	char *res=strchr(src,ch);
	if(res!=NULL){
	printf("Character '%c' found at index %ld.\n",ch,res-src);
	}
	else{
	printf("Character '%c' is not found in the string.\n",ch);
	}
}

