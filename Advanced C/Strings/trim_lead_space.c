#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	int i=0,j=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	while(isspace((unsigned char)str[i])){
		i++;
	}
	while(str[i]!='\0'){
		str[j++]=str[i++];
	}
	str[j]='\0';
	printf("String after triming the leading space:%s\n",str);
}
