#include<stdio.h>
#include<string.h>
int main(){
	char str[100],ret[100];
	int i,j=0;
	printf("Enter string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(i=0;str[i]!='\0';i++){
		char ch=str[i];
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
			continue;
		}
		ret[j++]=ch;
	}
	ret[j]='\0';
	printf("After removing the vowels:%s",ret);
}
