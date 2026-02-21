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
void deleteNodeAtEnd(struct Node **head){
	struct Node *temp,*prev;
	if(*head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	if((*head)->nxt==NULL){
		free(*head);
		*head=NULL;
		return;
	}
	temp=*head;
	while(temp->nxt!=NULL){
		prev=temp;
		temp=temp->nxt;
	}
	prev->nxt=NULL;
	free(temp);
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
	printf("Enter no nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Original List: ");
	displayList(head);
	deleteNodeAtEnd(&head);
	printf("Modified List: ");
	displayList(head);
}




