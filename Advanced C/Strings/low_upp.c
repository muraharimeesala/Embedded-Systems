#include<stdio.h>
#include<ctype.h>
int main(){
	char str[100];
	int i=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	int pos;
	for(i=0;str[i]!='\0';i++){
		if(islower(str[i])){
			str[i]=toupper(str[i]);
		}
	}
	printf("After converting the string:%s\n",str);
}

