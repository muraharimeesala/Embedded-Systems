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
void deleteByValue(struct Node **head,int key){
	temp=*head;
	if (*head == NULL) {
        printf("List is empty\n");
        return;
       	}
	if(temp->data == key){
        *head = temp->nxt;
        free(temp);
        return;
	}
	struct Node *prev=temp;
	struct Node *curr=temp->nxt;
	while(curr!=NULL && curr->data!=key){
		prev=curr;
		curr=curr->nxt;
	}
	if (curr == NULL) {
        printf("Key not found\n");
        return;
    	}
	prev->nxt=curr->nxt;
	free(curr);
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
        int n,i,data,key;
        printf("Enter no nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
	printf("Original List:\n");
        displayList(head);
	printf("Enter key to delete node:");
	scanf("%d",&key);
        printf("Updated List:\n");
        deleteByValue(&head,key);
        displayList(head);
}

