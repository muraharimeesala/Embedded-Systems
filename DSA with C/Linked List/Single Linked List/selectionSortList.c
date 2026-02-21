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
	struct Node *temp=*head;
	struct Node *pnew=createNode(data);
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(temp->nxt!=NULL){
		temp=temp->nxt;
	}
	temp->nxt=pnew;
}
struct Node *selectionSort(struct Node *head){
	struct Node *i,*j;
	int temp;
	for(i=head;i!=NULL && i->nxt!=NULL;i=i->nxt){
		for(j=i->nxt;j!=NULL;j=j->nxt){
			if(i->data>j->data){
				if(j!=i){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
				}
			}
		}
	}
	return head;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
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
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Original List:");
	displayList(head);
	selectionSort(head);
	printf("Sorted List:");
	displayList(head);
}
