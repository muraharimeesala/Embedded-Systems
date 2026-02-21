#include<stdio.h>
#include<ctype.h>
int main(){
	char str[100];
	int alpha=0,digit=0,special=0;
	int i=0;
	printf("Enter a string:");
	scanf("%s",str);
	while(str[i]!='\0' && str[i]!='\n'){
		if(isalpha(str[i])){
			alpha++;
		}
		else if(isdigit(str[i])){
			digit++;
		}
		else{
			special++;
		}
		i++;
	}
	printf("No of alphabets:%d\n",alpha);
	printf("No of digits:%d\n",digit);
	printf("No of special:%d\n",special);
}

