#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *pnew;
struct Node *createNodes(int data){
        pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Allocation Failed.\n");
                exit(1);
        }
        else{
                pnew->data=data;
                pnew->nxt=NULL;
        }
        return pnew;
}
void insertNodeAtEnd(struct Node **head,int newdata){
        pnew=createNodes(newdata);
        if(*head==NULL){
                *head = pnew;
		return;
	}
        temp=*head;
        while(temp->nxt!=NULL){
                temp=temp->nxt;
        }
        temp->nxt=pnew;
}
void reverseList(struct Node **head){
	struct Node *prev=NULL;
	struct Node *curr=*head;
	struct Node *next=NULL;
	while(curr!=NULL){
		next=curr->nxt;
		curr->nxt=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}
int printList(struct Node *head){
        temp=head;
        if(head==NULL){
                printf("List empty\n");
                exit(1);
        }
        while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->nxt;
        }
        printf("NULL\n");
}
int main(){
        int n,i,data;
        printf("Enter list size:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                insertNodeAtEnd(&head,data);
	}
	printf("Original List:\n");
	printList(head);
	reverseList(&head);
	printf("Reversed List:\n");
	printList(head);
}
