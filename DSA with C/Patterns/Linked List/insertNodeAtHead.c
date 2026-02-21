#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *head=NULL;
struct Node *temp;
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
void insertNodeAtHead(struct Node **head,int newdata){
	pnew=createNodes(newdata);
	if(*head==NULL){
		printf("List empty\n");
		exit(1);
	}
	pnew->nxt=*head;
	*head=pnew;
}
int printList(struct Node *head){
        struct Node *temp=head;
        while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->nxt;
        }
        printf("NULL\n");
}
int main(){
        int n,i,data,newdata;
        printf("Enter list size:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                pnew=createNodes(data);
                if(head==NULL){
                        head=temp=pnew;
                }
                else{
                        while(temp->nxt!=NULL){
                                temp=temp->nxt;
                        }
                        temp->nxt=pnew;
                }
        }
	printf("Original List:\n");
	printList(head);
	printf("Enter new node to insert at head:");
	scanf("%d",&newdata);
	insertNodeAtHead(&head,newdata);
	printf("Updated List:\n");
	printList(head);
}



