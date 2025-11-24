#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int i,n,res;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	res=strlen(str);
	printf("String length:%d\n",res);
}
				
	
