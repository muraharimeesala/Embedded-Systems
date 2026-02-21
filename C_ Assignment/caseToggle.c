#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	int i;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		if(isupper(str[i])){
			str[i]=tolower(str[i]);
		}
		else if(islower(str[i])){
			str[i]=toupper(str[i]);
		}
	}
	printf("After toggeling string:%s",str);
}

