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
void remDupliSortList(struct Node *head){
    struct Node *curr = head;

    if(curr == NULL){
        return;
    }
    while(curr->nxt != NULL){
        if(curr->data == curr->nxt->data){
            struct Node *dup = curr->nxt;
            curr->nxt = dup->nxt;
            free(dup);
        } else {
            curr = curr->nxt;
        }
    }
}
void displayList(struct Node *head){
        struct Node *temp=head;
        if(head==NULL){
                printf("List is empty.\n");
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
	int n,i,data;
	printf("Enter no nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	remDupliSortList(head);
	printf("Updated List:\n");
	displayList(head);
}

