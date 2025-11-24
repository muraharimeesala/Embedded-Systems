#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		if(str[i]>='A' && str[i]<='Z'){
			str[i]=str[i]+32;
		}
	}
	printf("Lowercase String:%s",str);
}
