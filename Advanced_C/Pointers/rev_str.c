#include<stdio.h>
int revStr(char *str){
	char *start=str;
	char *end=str;
	while(*end!='\0'){
		end++;
	}
	end--;
	while(start<end){
		char temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
}
int main(){
	char str[100];
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	char *ptr=str;
	while(*ptr!='\0'){
		if(*ptr=='\n'){
			*ptr='\0';
			break;
		}
		ptr++;
	}
	revStr(str);
	printf("Reverse of String:%s\n",str);
}

