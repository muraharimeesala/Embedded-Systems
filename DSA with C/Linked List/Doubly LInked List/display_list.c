#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *prev;
struct Node *nxt;
};
struct Node *head,*temp;
struct Node *createNode(int data){
struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
if(!pnew){
printf("Failed to allocate memory\n");
}
pnew->data=data;
pnew->prev=NULL;
pnew->nxt=NULL;
if(head==NULL){
    head=temp=pnew;
}
else{
temp->nxt=pnew;
pnew->prev=temp;
temp=pnew;
}
return pnew;
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
        createNode(data);
    }
    printf("Linked List: ");
display(head);
}

