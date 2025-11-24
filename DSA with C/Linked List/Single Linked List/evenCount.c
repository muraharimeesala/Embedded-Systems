
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allaction failed.\n");
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
	else{
		while(temp->nxt!=NULL){
			temp=temp->nxt;
		}
		temp->nxt=pnew;
	}
}
int evenCount(struct Node *head){
	int count=0;
	printf("Even numbers is: ");
	while(head!=NULL){
		if(head->data%2==0){
			printf("%d",head->data);
			count++;
		}
		head=head->nxt;
	}
	printf("\n");
	return count;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
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
	int n,data,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	displayList(head);
	printf("Even numbers of the Linked List:");
	int count=evenCount(head);
	printf("%d",count);
}
