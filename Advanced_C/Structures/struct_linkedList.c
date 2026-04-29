#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *nxt;
};
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(!pnew){
printf("Memory Error");
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
int n,i,value;
printf("Enter size of linked list:");
scanf("%d",&n);
printf("Enter %d nodes:\n",n);
for(i=0;i<n;i++){
scanf("%d",&value);
insertAtTail(&head,value);
}
printf("Linked list:");
display(head);
}




