#include<stdio.h>
#include<string.h>
int main(){
	char str[100];
	int freq[256]={0};
	int i=0,j=0;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\0'){
		if(str[i]!='\n' && !freq[(unsigned char)str[i]]){
			freq[(unsigned char)str[i]]=1;
			str[j++]=str[i];
		}
		i++;
	}
	str[j]='\0';
	printf("Updated string:\n%s\n",str);
}
