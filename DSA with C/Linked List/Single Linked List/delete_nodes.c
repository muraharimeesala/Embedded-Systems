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
void insertAtEnd(struct Node **head,int data){
	struct Node *pnew=createNode(data);
	struct Node *temp=*head;
	if(*head==NULL){
		*head=pnew;
	}
	else{
		while(temp->nxt!=NULL){
			temp=temp->nxt;
		}
		temp->nxt=pnew;
	}
}
void deleteNodes(struct Node **head){
	struct Node *temp=*head;
	struct Node *nxtNode;
	while(temp!=NULL){
		nxtNode=temp->nxt;
		printf("Deleted Node %d.\n",temp->data);
		free(temp);
		temp=nxtNode;
	}
	*head=NULL;  // reset head
	printf("All the nodes are deleted successfully.\n");
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(temp==NULL){
		printf("List is empty.\n");
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,data,target,newdata,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Original list:");
	displayList(head);
	printf("Deleting all nodes.....\n");
	deleteNodes(&head);
	printf("After deletion:");
	displayList(head);
}
