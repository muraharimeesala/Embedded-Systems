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
	 struct Node *temp=*head;
	 if(*head==NULL){
		 *head=pnew;
		 return;
	 }
	 else{
		while(temp->nxt!=NULL){
		temp=temp->nxt;
		}
	 }
	 temp->nxt=pnew;
}
void sortedList(struct Node *head){
	if(head==NULL){
		return;
	}
	struct Node *i,*j;
	int temp;
	for(i=head;i->nxt!=NULL;i=i->nxt){
		for(j=i->nxt;j!=NULL;j=j->nxt){
			if(i->data>j->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
		exit(1);
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
	printf("Enter No of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original list:");
	displayList(head);
	sortedList(head);
	printf("Sorted List:");
	displayList(head);
}




