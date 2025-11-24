#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,pos;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\0'){
		if(str[i]=='\n');
		str[i]='\0';
	}
	printf("Enter position to shift:");
	scanf("%d",&pos);
	for(i=0;str[i]!='\0',i++)

		
