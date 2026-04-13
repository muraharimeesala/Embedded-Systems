#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str[100];
	int i,j,len;
	char temp;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	len=strlen(str);
	for(i=0;i<len-1;i++){
		for(j=i+1;j<len;j++){
			if(str[i]>str[j]){
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	printf("After sorting the array:\n");
	printf("%s\n",str);
}
