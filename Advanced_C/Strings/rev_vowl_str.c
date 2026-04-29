#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100],vowl[100],res[100];
	int i,j,vCount=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	strcpy(res,str);
	for(i=0;str[i]!='\n';i++){
		char ch=tolower(str[i]);
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
			vowl[vCount++]=str[i];
		}
	}
	j=vCount-1;
	for(i=0;str[i]!='\0';i++){
		char ch=tolower(str[i]);
		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
			res[i]=vowl[j--];
		}
	}
	printf("String after revrsing the vowel:%s",res);
}
