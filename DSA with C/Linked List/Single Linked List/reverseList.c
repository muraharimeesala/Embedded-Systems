#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allocation failed.\n");
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
		while(temp->nxt!=NULL)
		temp=temp->nxt;
		temp->nxt=pnew;
	}
}
void display(struct Node *head){
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
void reverseList(struct Node **head){
	struct Node *prev=NULL,*curnt=*head,*next=NULL;
	while(curnt!=NULL){
		next=curnt->nxt;             //Store nxt nod
		curnt->nxt=prev;           //Reverse current node links
		prev=curnt;               //Move prev to current
		curnt=next;               //Move to nxt
	}
	*head=prev;
	printf("Linked list reversed successfully.\n");
}
int main(){
	struct Node *head=NULL;
	int n,data,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original List:");
	display(head);
	reverseList(&head);
	printf("Reversed List:");
	display(head);
}

