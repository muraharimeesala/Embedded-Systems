#include<stdio.h>
#include<ctype.h>
int main(){
	char str[100];
	int i=0,j=0;
	printf("Enter a string:\n");
	fgets(str,sizeof(str),stdin);
	while(str[i]!='\0'){
		if((str[i]>='A' && str[i]<='Z') ||(str[i]>='a' && str[i]<='z')){
			str[j]=str[i];
			j++;
		}
		i++;
	}
	str[j]='\0';
	printf("%s",str);
}
		

