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
void deleteAfterElement(struct Node **head,int newdata){
	struct Node *temp=*head;
	while(temp!=NULL && temp->data!=newdata){
		temp=temp->nxt;
	}
	if(temp==NULL || temp->nxt==NULL ){
		printf("No node exits after %d.\n",newdata);
		return;
	}
	struct Node *del=temp->nxt;
	temp->nxt=del->nxt;
	printf("Deleted %d after %d\n",del->data,newdata);
	free(del);
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
	int n,data,newdata,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Enter element after which you want insert:");
	scanf("%d",&newdata);
	printf("Original List:");
	displayList(head);
	deleteAfterElement(&head,newdata);
	printf("Updated List:");
	displayList(head);
}

