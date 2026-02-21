#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\n'){
		if(str[i]>='a'&& str[i]<='z'){
			str[i]=str[i]-32;
		}
		i++;
	}
	printf("After coverting the string to uppercase:%s\n",str);
}
