#include<stdio.h>
#include<unistd.h>

#define MAX 100
int stack[MAX];
int top=-1;

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void display(){
    printf("Stack elements are:\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
int main(){
    int n,x;
    printf("Enter Size Of Stack:");
    scanf("%d",&n);
    printf("Enter %d Stack Elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(x);
    }
    display();
    return 0;
}
