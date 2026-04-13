#include<stdio.h>
#include<unistd.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        stack[++top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    top--;
}
void display(){
    printf("Stack elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
int main(){ 
    int n,x,i;
    printf("Enter Stack Size:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }
    pop();
    display();
    return 0;
}
