#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	char ch;
	int i;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	printf("Enter insert character b/w spaces:");
	scanf("%c",&ch);
	for(i=0;str[i]!='\0';i++){
		if(str[i]==' '){
			str[i]=ch;
		}
	}
	printf("Modified string:%s\n",str);
}
