#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1000
int main(){
	char n1[MAX],n2[MAX];
	int result[2*MAX]={0};
	printf("Enter first pos number:");
	scanf("%s",n1);
	printf("Enter second pos number:");
	scanf("%s",n2);
	int len1=strlen(n1);
	int len2=strlen(n2);
	for(int i=len1-1;i>=0;i--){
		for(int j=len2-1;j>=0;j--){
			int mul=(n1[i]-'0')*(n2[j]-'0');
			int sum=mul+(result[i+j+1]);
			result[i+j]+=sum/10;
			result[i+j+1]=sum%10;
		}
	}
	int i=0;
	while(i<len1+len2 && result[i]==0){
		i++;
	}
	if(i==len1+len2){
		printf("Product: 0\n");
	}
	else{
		printf("Product: ");
		while(i<len1+len2){
			printf("%d",result[i]);
			i++;
		}
	}
}



