#include<stdio.h>
#include<string.h>
int main(){
	char str[1024];
	int i=0,j=0;
	char temp;
	printf("Enter string:\n");
	fgets(str,sizeof(str),stdin);
	while(str[j]!='\0')
		j++;
		j--;
	while(i<j){
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}
	printf("Reversed string:\n%s\n",str);
}
