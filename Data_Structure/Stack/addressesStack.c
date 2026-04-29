#include<stdio.h>
#include<stdlib.h>
struct Node{
        int data;
        struct Node *nxt;
};
struct Node *top=NULL;
void push(struct Node **top,int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Allocation Failed.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=*top;
        *top=pnew;
}
void addressesStack(struct Node *top){
	if(top==NULL){
		return;
	}
	while(top){
		printf("Data: %d\nAddress: %p\nNext: %p\n",top->data,(void*)top,(void*)top->nxt);
		top=top->nxt;
	}
}
void display(struct Node *top){
	if(top==NULL){
		printf("Stack Empty.\n");
		return;
	}
	struct Node *temp=top;
	while(temp!=NULL){
		printf("| %d |\n",temp->data);
		temp=temp->nxt;
	}
}
int main(){
        struct Node *top=NULL;
        int n,i,data;
        printf("Enter stack size:");
        scanf("%d",&n);
        printf("Enter %d values:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                push(&top,data);
        }
	printf("Stack Elements:\n");
	display(top);
	printf("ADDRESSES OF STACK:\n");
	addressesStack(top);
}
