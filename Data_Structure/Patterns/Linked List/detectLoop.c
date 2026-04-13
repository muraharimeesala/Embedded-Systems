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
void detectLoop(struct Node *head){
	struct Node *slow=head;
	struct Node *fast=head;
	while(fast!=NULL && fast->nxt!=NULL){
		slow=slow->nxt;
		fast=fast->nxt->nxt;
		if(slow==fast){
			printf("Detected Loop\n");
			return;
		}
	}
	printf("Loop Not Found\n");
}
void createLoop(int pos){
	temp=head;
	struct Node *loopNode=NULL;
	int count=1;
	while(temp->nxt!=NULL){
		if(count==pos){
			loopNode=temp;
		}
		temp=temp->nxt;
		count++;
	}
	temp->nxt=loopNode;
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
	int pos,choice;
	printf("Create Loop:(1-Yes /0=-No):");
	scanf("%d",&choice);
	if(choice==1){
		printf("Enter position to loop start:");
		scanf("%d",&pos);
		createLoop(pos);
	}
	detectLoop(head);
	printList(head);
}
