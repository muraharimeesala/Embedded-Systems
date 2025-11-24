#include<stdio.h>
#include<string.h>
int main(){
	int str[100],temp;
	int i,j;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	i=0;
	j=strlen(str)-1;
	while(i<j){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	printf("Reversed String:%s",str);
}
