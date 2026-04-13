#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 100
int n,data;

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(){
    struct node *pnew;
    pnew=(struct node*)malloc(sizeof(struct node));
    pnew->data=data;
    pnew->next=NULL;
    if(front==NULL){
        front=rear=pnew;
    }
    else{
        rear->next=pnew;
        rear=pnew;
    }
    printf("Inserted %d\n",rear->data);
}

void display(){
    struct node *temp;
    temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    printf("Enter size of queue:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        enqueue();
    }
    printf("Queue Elements:\n");
    display();
    return 0;
}
