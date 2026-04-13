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
int searchNode(struct Node *head,int key){
	temp=head;
	while(temp!=NULL){
		if(temp->data==key){
			return 1;
		}
		temp=temp->nxt;
	}
	return 0;
}
int main(){
        int n,i,data,key;
        printf("Enter list size:");
        scanf("%d",&n);
        printf("Enter %d nodes:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&data);
                pnew=createNodes(data);
                if(head==NULL){
                        head=temp=pnew;
                }
                else{
                        while(temp->nxt!=NULL){
                                temp=temp->nxt;
                        }
                        temp->nxt=pnew;
                }
        }
	printf("Enter key search node:");
	scanf("%d",&key);
	if(searchNode(head,key)){
			printf("%d Node found\n",key);
	}
	else{
		printf("%d Node not found\n",key);
	}
}


