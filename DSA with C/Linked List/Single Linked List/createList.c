#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	return pnew;
}
struct Node *createLinkedList(int n){
	struct Node *head=NULL,*temp=NULL,*pnew=NULL;
	int data,i;
	for(i=0;i<n;i++){
		printf("Enter value of %d node: ",i+1);
		scanf("%d",&data);
		pnew=createNode(data);
        	if(head==NULL){
		head=pnew;
		temp=head;
	        }
	        else{
		temp->nxt=pnew;
		temp=temp->nxt;
         	}
	}
	return head;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty\n");
	}
	printf("Linked List: ");
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n;
	printf("Enter No of nodes:");
	scanf("%d",&n);
	head=createLinkedList(n);
	displayList(head);
}


