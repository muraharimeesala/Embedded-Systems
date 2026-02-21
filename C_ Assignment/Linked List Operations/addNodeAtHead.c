#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNodes(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Error.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
       struct Node *pnew=createNodes(data);
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
void addNodeAtHead(struct Node **head,int newdata){
	struct Node *pnew=createNodes(newdata);
	if(*head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	pnew->nxt=*head;
	*head=pnew;
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
	int n,i,data,newdata;
	printf("Enter no nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Linked List:\n");
	displayList(head);
	printf("Enter new data:");
	scanf("%d",&newdata);
	addNodeAtHead(&head,newdata);
	printf("Updated List:\n");
	displayList(head);
}
