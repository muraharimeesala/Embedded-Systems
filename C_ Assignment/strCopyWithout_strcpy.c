#include<stdio.h>
#include<string.h>
int main(){
	char str1[100],str2[200];
	int i;
	printf("Enter first string:");
	fgets(str1,sizeof(str1),stdin);
	str1[strcspn(str1,"\n")]=='\0';
	for(i=0;str1[i]!='\0';i++){
		str2[i]=str1[i];
	}
	str2[i]='\0';
	printf("After copyimg the string:%s",str2);
}
