//removes all non-alphabetic characters from a string using isalpha().
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100],res[100];
	int i,j=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		if(isalpha(str[i])){
			res[j++]=str[i];
		}
	}
	res[j]='\0';
	printf("After filtering the string:%s\n",res);
}
