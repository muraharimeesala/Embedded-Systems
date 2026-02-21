#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,count=0;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		char ch=str[i];
		if(!(ch>='A' && ch<='Z'||ch>='a'&&ch<='z'||ch>='0'&&ch<='9'||ch==' ')){
			count++;
		}
	}
	printf("Count of special characters:%d",count);
}
