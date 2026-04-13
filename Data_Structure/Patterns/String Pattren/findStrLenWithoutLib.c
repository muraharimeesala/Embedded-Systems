#include<stdio.h>
#include<string.h>
int main(){
	char str[1024];
	int i,len=0;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	for(i=0;str[i]!='\0';i++){
		len++;
	}
	printf("Length of the string:%d\n",len);
}
