#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *temp;
struct stack *top=NULL;
void push(int data){
    temp=(struct stack*)malloc(sizeof(struct stack));
    if(temp==NULL){
        printf("Stack Overflow\n");
        return;
    }
    temp->data=data;
    temp->next=top;
    top=temp;
}
void display(){
    temp=top;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,i,data;
    printf("Enter Size Of Stack: ");
    scanf("%d",&n);
    printf("Enter %d Elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        push(data);
    }
    display(); 
    return 0;
}
