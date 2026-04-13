#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *nxt;
};
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(!pnew){
printf("Memory allocation failed");
return NULL;
}
pnew->data=data;
pnew->nxt=NULL;
return pnew;
}
void insertAtTail(struct Node **head,int data){
struct Node *pnew=createNode(data);
if(*head==NULL){
*head=pnew;
}
else{
struct Node *temp=*head;
while(temp->nxt!=NULL){
temp=temp->nxt;
}
temp->nxt=pnew;
}
}
void deleteAtHead(struct Node **head){
if(*head==NULL){
printf("List is empty\n");
return;
}
else{
struct Node *temp=*head;
*head=(*head)->nxt;
free(temp);
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
struct Node *head=NULL;
int n,value,i;
printf("Enter no of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("Enter value of node %d:",i);
	scanf("%d",&value);
insertAtTail(&head,value);
}
printf("Original List: ");
display(head);
deleteAtHead(&head);
printf("After deleting head: ");
display(head);
}

