
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
void createNodes(struct Node **head,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Allocation Failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	struct Node *temp=*head;
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(temp->nxt!=NULL){
		temp=temp->nxt;
	}
	temp->nxt=pnew;
}
struct Node *rearrangeEvenOdd(struct Node *head){
	struct Node *evenH=NULL,*evenT=NULL;
	struct Node *oddH=NULL,*oddT=NULL;
	while(head){
		struct Node *nxt=head->nxt;
		head->nxt=NULL;
		if(head->data%2==0){
			if(!evenH){
				evenH=evenT=head;
			}
			else{
				evenT->nxt=head;
				evenT=head;
			}
		}
		else{
			if(!oddH){
				oddH=oddT=head;
			}
			else{
				oddT->nxt=head;
				oddT=head;
			}
		}
		head=nxt;
	}
	if(!evenH)
		return oddH;
	evenT->nxt=oddH;
	return evenH;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int i,n,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d Nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNodes(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	head=rearrangeEvenOdd(head);
	printf("Updated List:\n");
	displayList(head);
}




