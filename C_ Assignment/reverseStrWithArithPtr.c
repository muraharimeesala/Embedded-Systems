#include<stdio.h>
#include<string.h>
int main(){
	char str[100],*start,*end;
	printf("Enter String:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	end=str+strlen(str);
	while(end>str){
		while(end>str && *(end-1)==' '){
			end--;
			start=end;
		}
		while(start>str && *(start-1)==' '){
			start--;
		}
		while(start<end)
		putchar(*start++);
		putchar(' ');
		end=start-1;
	}
}
