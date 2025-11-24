#include<stdio.h>
int main(){
	char str[100];
	char *ptr=str;
	int length=0;
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	while(*ptr!='\0'){
		length++;
		ptr++;
	}
	printf("Individual characters rev order:");
	for(int i=length;i>=0;i--){
		printf("%c\n",str[i]);
	}
}
