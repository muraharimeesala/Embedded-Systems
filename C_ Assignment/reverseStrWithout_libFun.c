#include<stdio.h>
#include<string.h>
int main(){
	char str[100],temp;
	int i,j;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	i=0;
	j=strlen(str)-1;
	for(i=0;i<j;i++,j--){
	temp=str[i];
	str[i]=str[j];
	str[j]=temp;
	}
	printf("Reversed string:%s",str);
}
