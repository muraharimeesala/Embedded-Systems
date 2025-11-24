#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
int main(){
	struct Node *Head=NULL,*Temp=NULL,*newNode;
	int n,i,value;
	printf("Enter no of node:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		newNode=(struct Node*)malloc(sizeof(struct Node));
		if(newNode==NULL){
			printf("Failed to allocate memory.\n");
			return 1;
		}
	printf("Enter value of node %d:",i);
	scanf("%d",&value);
	newNode->data=value;
	newNode->next=NULL;
	if(Head==NULL){
		Head=newNode;   // first Node
		Temp=Head;
	}
	else{
	        Temp->next=newNode;     // link last node to new node
		Temp=newNode;
	}
}
// Display the linked list
printf("Linked List: ");
Temp=Head;
while(Temp!=NULL){
	printf("%d->",Temp->data);
	Temp=Temp->next;
}
Temp=Head;
while(Temp!=NULL){
	struct Node *newNode=Temp->next;
	free(Temp);
	Temp=newNode;
}
}
