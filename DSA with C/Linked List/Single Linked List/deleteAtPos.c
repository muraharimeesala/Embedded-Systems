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
exit(1);
}
pnew->data=data;
pnew->nxt=NULL;
return pnew;
}
void insertAtTail(struct Node **head,int data){
struct Node *pnew=createNode(data);
if(*head==NULL){
*head=pnew;
return;
}
struct Node *temp=*head;
while(temp->nxt!=NULL){
temp=temp->nxt;
}
temp->nxt=pnew;
}
void deleteAtPos(struct Node **head,int pos){
if(*head==NULL){
printf("List is empty\n");
return;
}
struct Node *temp=*head;
if(pos==0){
*head=temp->nxt;
free(temp);
return;
}
// Traverse to node before the target position
for (int i=0;temp!=NULL&&i<pos-1;i++){
    temp=temp->nxt;
}
struct Node *nodeTodelete=temp->nxt;
temp->nxt=temp->nxt->nxt;
free(nodeTodelete);
}
void display(struct Node *head){
if(head==NULL){
printf("List is empty\n");
}
while(head!=NULL){
printf("%d->",head->data);
head=head->nxt;
}
printf("NULL\n");
}
int main(){
struct Node *head=NULL;
int n,data,pos;
printf("Enter no of nodes:");
scanf("%d",&n);
for (int i = 0; i < n; i++) {
        printf("Enter value of Node %d: ", i + 1);
        scanf("%d", &data);
        insertAtTail(&head,data);
}
printf("Enter position to delete at: ");
scanf("%d", &pos);
deleteAtPos(&head, pos);
printf("After deleting specific position: ");
display(head);
}

