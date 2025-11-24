#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char stack[MAX];
int top=-1;
void push(char c){
	if(top==MAX-1){
		printf("Stack over flow.\n");
	}
	else{
		stack[++top]=c;
	}
}
char pop(){
	if(top==-1){
		return '\0';
	}
	else{
		return stack[top--];
	}
}
int main(){
	char str[MAX];
	printf("Enter a string:");
	fgets(str,sizeof(str),stdin);
	str[strcspn(str,"\n")]='\0';
	for(int i=0;str[i]!='\0';i++){
		push(str[i]);
	}
	printf("Revsersed string:\n");
	while(top!=-1){
		printf("%c",pop());
	}
}
