#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int stack[50];
int top=-1;
void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}
int priority(char x){
	if(x=='('){
		return 1;
	}
	if(x=='+' || x=='-'){
		return 2;
	}
	if(x=='*' || x=='/'){
		return 3;
	}
	return 0;
}
int main(){
	char exp[50],x;
	int i=0;
	printf("Enter Expression:\n");
	scanf("%s",exp);
	while(exp[i]!='\0'){
		if(isalnum(exp[i])){
			printf("%c",exp[i]);
		}
		else if(exp[i]=='('){
			push(exp[i]);
		}
		else if(exp[i]==')'){
			while((x=pop())!='('){
				printf("%c",x);
			}
		}
		else{
			while(priority(stack[top]>=priority(exp[i])))
				printf("%c",pop());
			push(exp[i]);
		}
		i++;
	}
	while(top!=-1){
		printf("%c",pop());
	}
}

