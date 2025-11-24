#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	int i=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]=='\0';
	while(str[i]!='\0'){
		if(str[i]>='a' && str[i]<='z'){
			str[i]=str[i]-32;
		}
			i++;
	}
	printf("String after converting uppercase:%s",str);
}
