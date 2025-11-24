#include<stdio.h>
#include<string.h>
int main(){
	char str1[100],str2[100];
	int i,j;
	printf("Enter first String:");
	fgets(str1,sizeof(str1),stdin);
	str1[strcspn(str1,"\n")]=='\0';
	printf("Enter second String:");
	fgets(str2,sizeof(str2),stdin);
	str2[strcspn(str2,"\n")]=='\0';
	for(i=0;str1[i]!='\0';i++){
		for(j=0;str2[j]!='\0';j++){
			str1[i+j]=str2[j];
		}
		str1[i+j]='\0';
	}
	printf("After concatenate two string:%s",str1);
}

