#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *nxt;
};
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(!pnew){
printf("Memory allocation failed\n");
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
void deleteAtTail(struct Node **head){
if(*head==NULL){
printf("List is Empty\n");
}
if((*head)->nxt==NULL){
free(*head);
*head=NULL;
return;
}

struct Node *temp=*head;
while(temp->nxt->nxt!=NULL){
temp=temp->nxt;
}
free(temp->nxt);
temp->nxt=NULL;
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
int n,data,i;
printf("Enter no of nodes:");
scanf("%d",&n);
for(i=0;i<n;i++){
	printf("Enter value of node %d:",i);
	scanf("%d",&data);
	insertAtTail(&head,data);
	}
printf("Original List: ");
display(head);
deleteAtTail(&head);
printf("Modified List: ");
display(head);
}




