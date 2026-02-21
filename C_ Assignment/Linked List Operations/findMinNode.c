#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *createNode(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Failed to allocate memory.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
        struct Node *temp=*head;
        struct Node *pnew=createNode(data);
        if(*head==NULL){
                *head=pnew;
                return;
        }
        while(temp->nxt!=NULL){
                temp=temp->nxt;
        }
        temp->nxt=pnew;
}
int findMinNode(struct Node *head){
        int min;
        if(head==NULL){
                printf("List is empty.\n");
                return 0;
        }
	#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *createNode(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Failed to allocate memory.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
        struct Node *temp=*head;
        struct Node *pnew=createNode(data);
        if(*head==NULL){
                *head=pnew;
                return;
        }
        while(temp->nxt!=NULL){
                temp=temp->nxt;
        }
        temp->nxt=pnew;
}
int findMinNode(struct Node *head){
        int min;
        if(head==NULL){
                printf("List is empty.\n");
                return 0;
        }
        while(head!=NULL){
                if(head->data<min){
                        min=head->data;
                }
                head=head->nxt;
        }
        return min;
}
void displayList(struct Node *head){
        struct Node *temp=head;
        if(head==NULL){
                printf("List is empty.\n");
        }
        while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->nxt;
        }
        printf("NULL\n");
}
int main(){
        struct Node *head=NULL;
        int n,data,i;
        printf("Enter no of nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
        printf("Original List:\n");
        displayList(head);
        int Min=findMinNode(head);
        printf("Min Node:");
        printf("%d",Min);
}
        while(head!=NULL){
                if(head->data<min){
                        min=head->data;
                }
                head=head->nxt;
        }
        return min;
}
void displayList(struct Node *head){
        struct Node *temp=head;
        if(head==NULL){
                printf("List is empty.\n");
        }
        while(temp!=NULL){
                printf("%d->",temp->data);
                temp=temp->nxt;
        }
        printf("NULL\n");
}
int main(){
        struct Node *head=NULL;
        int n,data,i;
        printf("Enter no of nodes:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
        printf("Original List:\n");
        displayList(head);
        int Min=findMinNode(head);
        printf("Min Node:");
        printf("%d",Min);
}

