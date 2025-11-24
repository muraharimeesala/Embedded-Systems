#include<stdio.h>
#include<stdlib.h>
#include<sting.h>
int main(){
	char str[100];
	int count=0,i=0;
	printf("Enter a string: ");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\0'){
		if((str[i]!=' ' && str[i]!='\t' && str[i]!='\n')&&
			(i==0||str[i-1]==' ' || str[i-1]=='\t' || str[i-1]=='\n')){
				count++;
			}
		i++;
	}
	printf("No of  words in the string is: %d\n",count);
}
