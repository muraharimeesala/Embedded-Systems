#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *prev;
struct Node *nxt;
};
struct Node *head,*tail;
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(!pnew){
printf("Failed to allocate memory\n");
}
else{
pnew->data=data;
pnew->prev=NULL;
pnew->nxt=NULL;
}
return pnew;
}
void insertAtHead(struct Node **head,int data){
    struct Node *pnew=createNode(data);
    if(*head==NULL){
        *head=tail=pnew;
    }
    else{
        (*head)->prev=pnew;
        pnew->nxt=*head;
        *head=pnew;
    }
}
void display(struct Node *head){
struct Node *temp=head;
while(temp!=NULL){
printf("%d->",temp->data);
temp=temp->nxt;
}
printf("NULL\n");
}
int main(){
    int n,data,i;
    printf("enter size of node: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter data for node %d: ",i);
        scanf("%d",&data);
    insertAtHead(&head,data);
    }
    printf("Linked List: ");
    display(head);
}

