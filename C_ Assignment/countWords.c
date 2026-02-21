#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,words=0;
	printf("Enter a sentence:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		if((str[i]!=' ' && str[i+1]==' ' || str[i]!=' ' && str[i+1]=='\0')){
			words++;
		}
	}
	printf("Count of Words:%d",words);
}
