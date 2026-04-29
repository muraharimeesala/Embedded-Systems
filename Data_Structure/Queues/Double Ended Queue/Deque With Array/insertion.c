#include<stdio.h>
#include<unistd.h>

#define SIZE 100

int queue[SIZE];
int front=-1;
int rear=-1;
int n,value;

void insertAtBegin(int value){
    if((front==0 && rear==SIZE-1) || (front==rear+1)){
        printf("Queue is full\n");
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        if(front==0){
            front=SIZE-1;
        }
        else{
            front--;
        }
        queue[front]=value;
        printf("Inserted At Begin: %d\n",value);
    }
}

void insertAtEnd(int value){
    if((front==0 && rear==SIZE-1) || (front==rear+1)){
        printf("Queue is full\n");
    }
    else{
        if(rear==-1){
            front=0;
            rear=0;
        }
        else if(rear==SIZE-1){
            rear=0;
        }
        else{
            rear++;
        }
        queue[rear]=value;
        printf("Inserted At End: %d\n",value);
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
    else{
        for(int i=front;i<SIZE;i++){
            printf("%d ",queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }   
    printf("\n");
}

int main(){
    printf("Enter Size of Queue:");
    scanf("%d",&n);
    printf("Enter %d Queue Elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertAtEnd(value);
    }
    printf("Before Insertion:\n");
    display();
    printf("Enter Value to Insert At Begin:");
    scanf("%d",&value);
    insertAtBegin(value);
    printf("Enter Value to Insert At End:");
    scanf("%d",&value);
    insertAtEnd(value);
    printf("After Insertion At End:\n");
    display();
    }
