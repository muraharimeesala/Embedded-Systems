#include<stdio.h>
#include<ctype.h>
int main(){
	char str[100];
	int i=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	for(i=0;i<str[i]!='\0';i++){
		if(isupper(str[i])){
			str[i]=tolower(str[i]);
		}
	}
	printf("After converting the string:%s\n",str);
}

