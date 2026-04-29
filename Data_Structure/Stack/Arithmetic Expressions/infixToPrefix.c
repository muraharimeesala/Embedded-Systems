#include<stdio.h>
#include<ctype.h>
#include<string.h>
int stack[50];
int top=-1;
void push(char x){
	stack[++top]=x;
}
char pop(){
	return stack[top--];
}
int priority(char x){
	if(x=='*'||x=='/'){
		return 2;
	}
	if(x=='+'||x=='-'){
		return 1;
	}
	return 0;
}
void reverse(char exp[]){
	int i,j;
	char temp;
	for(i=0,j=strlen(exp)-1;i<j;i++,j--){
		temp=exp[i];
		exp[i]=exp[j];
		exp[j]=temp;
	}
}
int main(){
	char exp[50],res[50];
	int i,k=0;
	printf("Enter expression:\n");
	scanf("%s",exp);
	reverse(exp);
	for(i=0;exp[i];i++){
		if(exp[i]==')'){
			push(exp[i]);
		}
		else if(exp[i]=='('){
			while(stack[top]!=')')
				res[k++]=pop();
			pop();
		}
		else if(isalnum(exp[i]))
			res[k++]=exp[i];
		else{
			while(top!=-1 && priority(stack[top]>priority(exp[i])))
				res[k++]=pop();
			push(exp[i]);
		}
	}
	while(top!=-1)
		res[k++]=pop();
	res[k]='\0';
	reverse(res);
	printf("Prefix expression:\n%s",res);
}

	
