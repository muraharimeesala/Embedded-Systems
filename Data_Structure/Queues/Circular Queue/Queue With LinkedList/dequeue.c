#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 100

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
        rear->next = front;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
    printf("Enqueued :%d\n",value);
    return;
}

int dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp = front;
    printf("Dequeued :%d\n",front->data);
    front = front->next;
    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    free(temp);
    return 0;
}

void display()
{
    struct node *temp = front;
    printf("Queue : ");
    while(temp != rear)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

int main(){
    int n,data;
    printf("Enter Size of Queue : ");
    scanf("%d",&n);
    printf("Enter %d Queue Elements:\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Before Dequeue:\n");
    display();
    dequeue();
    printf("After Dequeue:\n");
    display();
    return 0;
}
