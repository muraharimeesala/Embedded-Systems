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
void findStartingNode(struct Node *head){
	struct Node *slow=head;
	struct Node *fast=head;
	while(fast!=NULL && fast->nxt!=NULL){
		slow=slow->nxt;
		fast=fast->nxt->nxt;
		if(slow==fast){
			break;
		}
	}
	if(fast==NULL || fast->nxt==NULL){
		return;
	}
	slow=head;
	while(slow!=fast){
		slow=slow->nxt;
		fast=fast->nxt;
	}
}
int printList(struct Node *head){
        temp=head;
        if(head==NULL){
                printf("List empty\n");
                exit(1);
        }
	int count=0;
        while(temp!=NULL && count<20){
                printf("%d->",temp->data);
                temp=temp->nxt;
		count++;
        }
	if(temp!=NULL){
		printf("....(Loop Detected)\n");
	}
	else{
		printf("NULL\n");
	}
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
	if(n>=0){
		struct Node *startLoop=head->nxt;
		struct Node *last=head;
		while(last->nxt!=NULL)
		last=last->nxt;
		last->nxt=startLoop;
		printf("Loop  Created: last node points to node with value:%d\n",startLoop->data);
	}
	findStartingNode(head);
}

