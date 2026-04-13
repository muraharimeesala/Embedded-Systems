#include<stdio.h>
#include<string.h>
char stack[1024];
int top=-1;
void push(char ch){
	stack[++top]=ch;
}
char pop(){
	return stack[top--];
}
int main(){
	char str[1024];
	int i;
	printf("Enter String:\n");
	scanf("%s",str);
	for(i=0;str[i];i++){
		push(str[i]);
	}
	for(i=0;str[i];i++){
		str[i]=pop();
	}
	printf("Reversed String:\n%s\n",str);
}
