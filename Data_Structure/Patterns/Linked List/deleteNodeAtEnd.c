#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *nxt;
};
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *pnew;
struct Node *createNodes(int data){
        pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Error.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
        pnew=createNodes(data);
        temp=*head;
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
	temp=*head;
	if(*head==NULL){
		printf("List empty\n");
		exit(1);
	}
	if((*head)->nxt==NULL){
		free(*head);
		*head=NULL;
	}
	while(temp->nxt->nxt!=NULL){
		temp=temp->nxt;
	}
	free(temp->nxt);
	temp->nxt=NULL;
}
int displayList(struct Node *head){
	temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
        int n,i,data;
        printf("Enter no nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
        printf("Original List:\n");
        displayList(head);
	printf("Updated List:\n");
	deleteNodeAtEnd(&head);
	displayList(head);
}
