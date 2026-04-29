#include<stdio.h>
#include<string.h>
int main(){
	char str[100],ch,newCh;
	int i,lastIdx=-1;
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
			lastIdx=i;
		}
	}
	if(lastIdx!=-1){
	str[lastIdx]=newCh;
		printf("String after replcing the new character:%s\n",str);
	}
	else{
		printf("Character %c is not found int the string.\n",ch);
	}
}
