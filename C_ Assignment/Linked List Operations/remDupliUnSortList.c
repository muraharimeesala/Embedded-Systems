#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *createNode(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Alloation Failed.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
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
}
void remDupliUnSortList(struct Node *head){
    struct Node *curr, *runner, *dup;
    for(curr=head;curr!= NULL;curr=curr->nxt){
        runner=curr;
        while(runner->nxt!=NULL){
            if(runner->nxt->data==curr->data){
                dup=runner->nxt;
                runner->nxt=dup->nxt;
                free(dup);
            }else{
                runner=runner->nxt;
            }
        }
    }
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
		return;
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
        for(i=0;i<n;i++){
                printf("Enter value of %d node:",i);
                scanf("%d",&data);
                addNodeAtEnd(&head,data);
        }
	printf("Original List:\n");
	displayList(head);
	remDupliUnSortList(head);
	printf("Updated List:\n");
	displayList(head);
}
