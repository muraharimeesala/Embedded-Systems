#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	int i=0,j=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	i=strlen(str)-1;
	while(i>=0 && isspace((unsigned char)str[i])){
		i--;
	}
	str[i+1]='\0';
	printf("String after triming the trailing space:\"%s\"\n",str);
}
