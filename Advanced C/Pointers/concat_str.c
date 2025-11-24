#include<stdio.h>
int main(){
	char s1[100],s2[100];
	char *p,*q;
	printf("Enter first string:");
	scanf("%s",s1);	
	printf("Enter second string:");
	scanf("%s",s2);
	p=s1;
	q=s2;
	while(*p!='\0'){
		p++;
	}
	while(*q!='\0'){
		*p=*q;
		p++;
		q++;
	}
	*p='\0';
	printf("Concatenated string:%s\n",s1);
}
