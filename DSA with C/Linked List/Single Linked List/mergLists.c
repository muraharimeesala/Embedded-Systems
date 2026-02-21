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
void insertAtTail(struct Node **head,int data){
	struct Node *pnew=createNode(data);
	if(*head==NULL){
		*head=pnew;
		return;
	}
	struct Node *temp=*head;
	while(temp->nxt!=NULL)
	temp=temp->nxt;
	temp->nxt=pnew;
}
struct Node *concatenateLists(struct Node *List1,struct Node *List2){
	if(List1==NULL) return List2;
	if(List2==NULL) return List1;
	struct Node *temp=List1;
	while(temp->nxt!=NULL)
	temp=temp->nxt;
	temp->nxt=List2;
	return List1;
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
	struct Node *List1=NULL;
	struct Node *List2=NULL;
	struct Node *Merg=NULL;
	int i,data,n1,n2;
	printf("Enter no of nodes of list1:");
	scanf("%d",&n1);
	for(i=0;i<n1;i++){
		printf("Enter value of %d node of list1:",i);
		scanf("%d",&data);
		insertAtTail(&List1,data);
	}
	printf("Enter no of nodes of list2:");
	scanf("%d",&n2);
	for(i=0;i<n2;i++){
		printf("Enter value of %d node of list2:",i);
		scanf("%d",&data);
		insertAtTail(&List2,data);
	}
	printf("First List:");
	displayList(List1);
	printf("Second List:");
	displayList(List2);
	Merg=concatenateLists(List1,List2);
	printf("After merging the two lists:");
	displayList(Merg);
}

