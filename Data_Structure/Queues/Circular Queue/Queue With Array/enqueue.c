#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 100
int queue[SIZE];
int front=-1;
int rear=-1;
int n;

void enqueue(int value)
{
    if((front==0&&rear==SIZE-1)||(front==rear+1))     //Queue is full
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)              //Queue is empty
    {
        front=rear=0;
    }
    else if(rear==SIZE-1)         //Queue is not full
    {
        rear=0;
    }
    else                       //Queue is not full
    {
        rear++;
    }
    queue[rear]=value;
}

void display()
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main()
{
    int value;
    printf("Enter Queue Size:");
    scanf("%d",&n);
    printf("Enter %d Queue Elements:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        enqueue(value);
    }
    printf("Queue Elements:\n");
    display();
    return 0;
}
