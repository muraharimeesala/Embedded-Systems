#include<stdio.h>
#include<stdlib.h>

#define SIZE 100

int stack1[SIZE],stack2[SIZE],top1=-1,top2=-1;
int size1=SIZE,size2=SIZE;
int value;

void enqueue(int value){
    if(top1==size1-1){
        printf("Queue OverFlow\n");
        exit(1);
    }
    else{
        if(top1==-1){
            top1=0;
        }
        top1++;
        stack1[top1]=value;
    }
}

int dequeue(){
    if(top1==-1 || top2==-1){
        printf("Queue UnderFlow\n");
        exit(1);
    }
    if(top2==-1){
        while(top1==-1){
            top2++;
            stack2[top2]=stack1[top1];
            top1--;
        }
    }
    return stack2[top2--];
}
void display(){
    if(top1==-1){
        printf("Queue is empty\n");
        exit(1);
    }
    printf("Queue Elements:\n");
    for(int i=top2;i<=top1;i++){
        printf("%d ",stack1[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter queue size:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enqueue(value);
    }
    display();
    printf("Deleted : %d\n",dequeue());
    display();
    return 0;
}
