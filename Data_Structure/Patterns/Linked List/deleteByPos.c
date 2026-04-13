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
void deleteByPos(struct Node **head,int pos){
	if(*head==NULL && pos<=0){
		return;
	}
	temp=*head;
	if(pos==1){
		*head=temp->nxt;
		free(temp);
		return;
	}
	for(int i=1;i<pos-1 && temp->nxt!=NULL;i++){
		temp=temp->nxt;
	}
	if(temp->nxt==NULL){
		printf("Invalid position\n");
		return;
	}
	struct Node *del=temp->nxt;
	temp->nxt=del->nxt;
	free(del);
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
        int n,i,data,pos;
        printf("Enter no nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
        printf("Original List:\n");
        displayList(head);
        printf("Enter position to delete node:");
        scanf("%d",&pos);
        printf("Updated List:\n");
        deleteByPos(&head,pos);
        displayList(head);
}

