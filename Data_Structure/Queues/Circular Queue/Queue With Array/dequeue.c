#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 100

int queue[SIZE];
int front=-1;
int rear=-1;
int n,value;

void enqueue()
{
    if((front==0 && rear==SIZE-1)||(front==rear+1))
    {
        printf("Queue is full\n");
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==SIZE-1)
    {
        rear=0;
    }
    else
    {
        rear++;
    }
    queue[rear]=value;
    printf("Enqueued: %d\n",value);
}

void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n",queue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==SIZE-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}
void display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Enter Size of Queue: ");
    scanf("%d",&n);
    printf("Enter %d Queue elements:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        enqueue();
    }
    printf("Before Dequeue:\n");
    display();
    dequeue();
    printf("After Dequeue:\n");
    display();
    return 0;
}
    
