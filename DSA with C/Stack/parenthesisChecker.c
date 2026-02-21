#include<stdio.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char x){
	stack[++top]=x;
}
char pop(){
	return stack[top--];
}
int main(){
	char exp[SIZE];
	int i,flag=1;
	printf("Enter Expression:\n");
	scanf("%s",exp);
	for(i=0;i<exp[i];i++){
		if(exp[i]=='('){
			push('(');
		}
		else if(exp[i]==')'){
			if(top==-1){
				flag=0;
				break;
			}
			pop();
		}
	}
	if(flag && top==-1){
		printf("Balanced Parentheses.\n");
	}
	else{
		printf("UnBalanced Parentheses.\n");
	}
}

