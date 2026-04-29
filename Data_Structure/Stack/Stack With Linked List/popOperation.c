#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack* next;
};

struct stack *top = NULL;
struct stack *temp;

void push(int data){
    if(temp == NULL){
        printf("Stack is full\n");
    }
    temp = (struct stack*)malloc(sizeof(struct stack));
    temp->data = data;
    temp->next = top;
    top = temp;
    printf(" %d pushed to stack\n",data);
}
void pop(){
    if(top == NULL){
        printf("Stack is empty\n");
    }
    temp = top;
    top = top->next;
    free(temp);
    printf("\n%d Element popped from stack\n\n",top->data);
}
void display(){
    temp = top;
    while(temp != NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
int main(){
    int n,i,data;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        push(data);
    }
    printf("Before pop operation\n");
    display();
    pop();
    printf("After pop operation\n");
    display();
    return 0;
}
