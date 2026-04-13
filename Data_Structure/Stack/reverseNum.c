#include <stdio.h>
#include<math.h>
#define MAX 50
int stack[MAX], top=-1;
void push(int x){
	stack[++top]=x;
}
int pop(){ 
	return stack[top--]; 
}
int main(){
    int num, digit;
    printf("Enter number: ");
    scanf("%d",&num);
    while(num){
        push(num%10);
        num/=10;
    }
    printf("Reversed number: ");
    while(top!=-1){
	    printf("%d",pop());
    }
    printf("\n");
}

























