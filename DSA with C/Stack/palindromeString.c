#include<stdio.h>
char stack[100];
int top=-1;
void push(int x){
        stack[++top]=x;
}
char pop(){
        return stack[top--];
}
int main(){
        char str[100],i;
	printf("Enter string:\n");
	scanf("%s",str);
        for(i=0;str[i];i++){
                push(str[i]);
        }
        for(i=0;str[i];i++){
                if(str[i]!=pop()){
                        printf("Its not palidrome.\n");
                        return 0;
                }
        }
        printf("Its a palindrome.\n");
}

