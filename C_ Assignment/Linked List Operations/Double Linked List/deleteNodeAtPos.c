#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *nxt;
        struct Node *prev;
};
struct Node *createNode(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Failed\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        pnew->prev=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
        struct Node *pnew=createNode(data);
        struct Node *temp=*head;
        if(*head==NULL){
                *head=pnew;
                return;
        }
        while(temp->nxt!=NULL){
                temp=temp->nxt;
        }
        temp->nxt=pnew;
        pnew->prev=temp;
        temp=pnew;
}
void deleteNodeAtPos(struct Node **head,int pos){
	struct Node *temp=*head;
	while(temp && temp->nxt!=pos){
		temp=temp->nxt;
	}
	if(temp==NULL){
		return;
	}
	if(temp->prev!=NULL){
		temp->prev->nxt=temp->nxt;
	}
	else{
		*head=temp->nxt;
	}
	if(temp->prev){
		temp->nxt->prev=temp->prev;
	}
	free(temp);
}
	
