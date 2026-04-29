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
void searchElement(struct Node *head,int key){
	struct Node *temp=head;
	int pos=1;
	int found=0;
	while(temp!=NULL){
		if(temp->data==key){
			printf("Element %d is found at position %d.\n",key,pos);
			found=1;
			break;
		}
		temp=temp->nxt;
		pos++;
	}
}
int main(){
	struct Node *head=NULL;
	int n,data,i,key;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter Value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	display(head);
	printf("Enter Element to search:");
	scanf("%d",&key);
	searchElement(head,key);
}

