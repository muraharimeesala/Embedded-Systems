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
void insertAtPos(struct Node **head,int data,int pos){
	struct Node *pnew=createNode(data);
	struct Node *temp=*head;
	if(pos==0){
		pnew->nxt=*head;
		*head=pnew;
		return;
	}
	for(int i=0;i<pos-1&&temp!=NULL;i++){
		temp=temp->nxt;
	}
	pnew->nxt=temp->nxt;
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
// Helper function: Insert at tail for building initial list
void insertAtTail(struct Node **head,int data) {
    struct Node *pnew=createNode(data);
    if(*head==NULL){
        *head=pnew;
        return;
    }
    struct Node *temp=*head;
    while(temp->nxt!=NULL) {
        temp=temp->nxt;
    }
    temp->nxt=pnew;
}
int main(){
    struct Node *head=NULL;
    int n,i,data,pos;
    printf("Number of node to insert:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("Enter value for node %d: ",i);
    scanf("%d",&data);
    insertAtTail(&head,data);
    }
    printf("Original List:");
    display(head);
    printf("Enter value to insert at pos:");
    scanf("%d",&data);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    insertAtPos(&head,data,pos);
    printf("Modified List:");
    display(head);
}
