#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nxt;
};
//Creating Node
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(pnew==NULL){
    printf("Memory Error\n");
    exit(1);
}
pnew->data=data;
pnew->nxt=NULL;
return pnew;
}
//Inserting at Ending
void insertAtTail(struct Node **head,int data){
    struct Node *pnew=createNode(data);
    if(*head==NULL){
    *head=pnew;
    return;
    }
    // Otherwise,traverse to the last node
    struct Node *temp=*head;
    while(temp->nxt!=NULL) {
        temp=temp->nxt;
    }
    // Link the last node to the new node
    temp->nxt=pnew;
}
//Display the linked list
void display(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->nxt;
    }
    printf("NULL\n");
}
int main(){
    struct Node *head=NULL;
    int n,i,data;
    printf("Number of node to insert:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("Enter value for node %d: ",i);
    scanf("%d",&data);
    insertAtTail(&head,data);
    }
    printf("Original List:");
    display(head);
    printf("Enter value to insert at tail:");
    scanf("%d",&data);
    insertAtTail(&head,data);
    printf("Modified List:");
    display(head);
}



