#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char str[100];
	int i,j;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]=='\0';
	i=0;
	j=strlen(str)-1;
	while(i<j){
		while(i<j && !(strchr("AEIOUaeiou",str[i])))
		i++;
		while(i<j && !(strchr("AEIOUaeiou",str[j])))
		j--;
		if(i<j){
			char temp=str[i];
			str[i]=str[j];
			str[j]=temp;
			i++;
			j--;
		}
	}
	printf("String after reverse the vowels:%s\n",str);
}
