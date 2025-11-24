#include<stdio.h>
#include<string.h>
int main(){
	char str1[100],str2[100];
	int i=0,result=0;
	printf("Enter first string:");
	scanf("%s",str1);
	printf("Enter second string:");
	scanf("%s",str2);
	while(str1[i]!='\0'){
		if(str1[i]=='\n'){
		str1[i]='\0';
		break;
		}
		i++;
	}
	i=0;
	while(str2[i]!='\0'){
		if(str2[i]=='\n'){
		str2[i]='\0';
		break;
		}
		i++;
	}
	i=0;
	while(str1[i]!='\0' && str2[i]!='\0'){
		if(str1[i]!=str2[i]){
			result=str1[i]-str2[i];
			break;
		}
		i++;
	}
	if(result==0){
	       result=str1[i]-str2[i];
	}
	if(result==0){
		printf("Both the strings are equal.\n");
	}
	else if(result>0){
		printf("First string is bigger then second string.\n");
	}
	else{
		printf("First string is smaller then second string.\n");
	}
}
