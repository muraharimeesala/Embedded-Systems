#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 100

int n,data;
struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int data){
    struct node *pnew=(struct node*)malloc(sizeof(struct node));
    if(pnew==NULL){
        printf("Memory Error\n");
        return;
    }
    pnew->data=data;
    pnew->next=NULL;
    if(front==NULL){
        front=rear=pnew;
    }
    else{
        rear->next=pnew;
        rear=pnew;
    }
    printf("Enqueued :%d\n",rear->data);
}

void display(){
    struct node *temp=front;
    if(front==NULL){
        printf("Queue is Empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    printf("Enter Size of Queue: ");
    scanf("%d",&n);
    printf("Enter %d Queue Elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Queue Elements:\n");
    display();
    return 0;
}
