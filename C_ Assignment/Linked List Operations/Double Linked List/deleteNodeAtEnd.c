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
void addNodeAtEnd(struct Node **head,struct Node **tail,int data){
        struct Node *pnew=createNode(data);
        struct Node *temp=*head;
        if(*head==NULL){
                *head=*tail=pnew;
                return;
        }
        else{
		(*tail)->nxt=pnew;
		pnew->prev=*tail;
		*tail=pnew;
	}
}
void deleteNodeAtEnd(struct Node **head,struct Node **tail){
    if(*head==NULL){
        printf("List Empty\n");
        return;
    }
    struct Node *temp=*tail;
    if(*head==*tail){   // single node
        *head=*tail=NULL;
    }
    else{
	    *tail = temp->prev;     // move tail back
           (*tail)->nxt = NULL;    // disconnect last node
    }
    free(temp);
}
void displayList(struct Node *head){
        struct Node *temp=head;
        if(head==NULL){
                printf("List Empty.\n");
                exit(1);
        }
        while(temp!=NULL){
                printf("%d<->",temp->data);
                temp=temp->nxt;
        }
        printf("NULL\n");
}
int main(){
        struct Node *head=NULL,*tail=NULL;
        int n,i,data;
        printf("Enter no of nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,&tail,data);
        }
        printf("Original List:\n");
        displayList(head);
        deleteNodeAtEnd(&head,&tail);
        printf("Updated List:\n");
        displayList(head);
}

