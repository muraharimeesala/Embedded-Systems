#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Failed to allocate memory.\n");
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
	while(temp->nxt!=NULL)
		temp=temp->nxt;
		temp->nxt=pnew;
}
void swapToNodes(struct Node **head,int x,int y){
	if(x==y) return;
	struct Node *prevX=NULL,*currX=*head;
	struct Node *prevY=NULL,*currY=*head;

	while(currX && currX->data!=x){
		prevX=currX;
		currX=currX->nxt;
	}
	while(currY && currY->data!=y){
		prevY=currY;
		currY=currY->nxt;
	}
	if(currX==NULL || currY==NULL){
		printf("One or Both the elements not found in the list.\n");
		return;
	}
	if(prevX!=NULL){
		prevX->nxt=currY;
	}
	else{
		*head=currY;
	}
	if(prevY!=NULL){
		prevY->nxt=currX;
	}
	else{
		*head=currX;
	}
	struct Node *temp=currX->nxt;
	currX->nxt=currY->nxt;
	currY->nxt=temp;
}
void displayList(struct Node *head){
	while(head!=NULL){
		printf("%d->",head->data);
		head=head->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,data,x,y,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original List:");
	displayList(head);
	printf("Enter X value:");
	scanf("%d",&x);
	printf("Enter Y value:");
	scanf("%d",&y);
	swapToNodes(&head,x,y);
	printf("Linked list after swapping %d and %d:\n",x,y);
	displayList(head);
}


