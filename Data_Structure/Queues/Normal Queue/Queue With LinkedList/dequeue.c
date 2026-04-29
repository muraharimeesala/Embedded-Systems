#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    printf("Enqueued %d\n", x);
}

int dequeue()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp=front;
    printf("Dequeued %d\n", front->data);
    front = front->next;
    free(temp);
    return 0;
}

int display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    struct node *temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int main(){
    int n,x;
    printf("Enter Size of Queue: ");
    scanf("%d", &n);
    printf("Enter %d Queue elements:\n", n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    printf("Before Dequeue\n");
    display();
    dequeue();
    printf("After Dequeue\n");
    display();
    return 0;
}
