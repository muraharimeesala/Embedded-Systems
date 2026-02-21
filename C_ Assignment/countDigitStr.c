#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	int i,count=0;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		if(isdigit(str[i])){
			count++;
		}
	}
	printf("No of digits:%d",count);
}
