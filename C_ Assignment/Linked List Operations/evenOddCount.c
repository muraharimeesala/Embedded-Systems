#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Allocation Failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
	struct Node *pnew=createNode(data);
	if(*head==NULL){
		*head=pnew;
		return;
	}
	struct Node *temp=*head;
	while(temp->nxt!=NULL){
		temp=temp->nxt;
	}
	temp->nxt=pnew;
}
void evenOddCount(struct Node *head){
	struct Node *temp=head;
	printf("Even Numbers:\n");
	while(temp!=NULL){
		if(temp->data%2==0){
			printf("%d->",temp->data);
		}
		temp=temp->nxt;
	}
	printf("NULL\n");
	temp=head;
	printf("Odd Numbers:\n");
        while(temp!=NULL){
                if(temp->data%2!=0){
                        printf("%d->",temp->data);
                }       
                temp=temp->nxt;
        }
	printf("NULL\n");
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
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
	int n,i,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d Nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	evenOddCount(head);
}
