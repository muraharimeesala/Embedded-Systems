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
void insertAtEnd(struct Node **head,int data){
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
void insertBeforeElement(struct Node **head,int target,int newdata){
	struct Node *temp=*head;
	struct Node *prev=NULL;
	if(temp==NULL){
		printf("List is empty.\n");
		return;
	}
	// target is at head: insert new node at front
	if(temp->data==target){
		struct Node *pnew=createNode(newdata);
		pnew->nxt=*head;
		*head=pnew;
		printf("Inserted %d before %d.\n",newdata,target);
	}
	 // search for target
	while(temp!=NULL && temp->data!=target){
		prev=temp;
		temp=temp->nxt;
	}
	if(temp==NULL){
		printf("Element %d is not found int list.\n",target);
		return;
	}
	// insert between prev and temp
	struct Node *pnew=createNode(newdata);
	prev->nxt=pnew;
	pnew->nxt=temp;
	printf("Inserted %d after %d\n",newdata,target);
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(temp==NULL){
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
	int n,data,target,newdata,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Enter element after which you want insert:");
	scanf("%d",&target);
	printf("Enter value to insert:");
	scanf("%d",&newdata);
	printf("Original List:");
	displayList(head);
	insertBeforeElement(&head,target,newdata);
	printf("Updated List:");
	displayList(head);
}

