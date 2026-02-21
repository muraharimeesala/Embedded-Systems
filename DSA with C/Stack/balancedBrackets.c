#include<stdio.h>
#include<string.h>
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(int ch){
	if(top==SIZE-1){
		printf("Stack OverFlow\n");
		return;
	}
	else{
		stack[++top]=ch;
	}
}
char pop(){
	if(top==-1){
		printf("Stack UnderFlow.\n");
	}
	else{
		return stack[top--];
	}
}
int match(int a,int b){
	if(a=='('&&b==')'){
		return 1;
	}
	if(a=='{'&&b=='}'){
		return 1;
	}
	if(a=='['&&b==']'){
		return 1;
	}
	return 0;
}
int main(){
	char exp[SIZE];
	int i,flag=1;
	printf("Enter Expression:\n");
	scanf("%s",exp);
	for(i=0;exp[i];i++){
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
			push(exp[i]);
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
			if(top==-1 || !match(pop(),exp[i])){
				flag=0;
				break;
			}
		}
	}
	if(flag && top==-1){
		printf("Balanced Brackets.\n");
	}
	else{
		printf("UnBalaned Brackets.\n");
	}
}
