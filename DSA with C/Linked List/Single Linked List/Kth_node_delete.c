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
void deleteKthNodes(struct Node **head,int k){
	if(*head==NULL || k<=0){
		return;
	}
	struct Node *temp=*head;
	if(k==1){
		*head=temp->nxt;
		free(temp);
		return;
	}
	int i;
	for(i=1;i<k-1 && temp!=NULL;i++){
		temp=temp->nxt;
	}
	if(temp==NULL || temp->nxt==NULL){
		printf("Position out of range.\n");
		return;
	}
	struct Node *del=temp->nxt;
	temp->nxt=del->nxt;
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
	int n,data,k,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Enter K value:");
	scanf("%d",&k);
	printf("Original list:");
	displayList(head);
	deleteKthNodes(&head,k);
	printf("After deletion:");
	displayList(head);
}
