#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *nxt;
};
struct Node *createNode(int data){
    struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
    if(pnew==NULL){
        printf("Failed to memory allocation.\n");
        exit(1);
    }
    pnew->data=data;
    pnew->nxt=NULL;
    return pnew;
}
void insertAtEnd(struct Node **head,int data){
    struct Node *pnew=createNode(data);
    if(*head==NULL){
        *head=pnew;
        return;
    }
    else{
        struct Node *temp=*head;
        while(temp->nxt!=NULL){
            temp=temp->nxt;
        }
            temp->nxt=pnew;
    }
}
void reverseList(int arr[],int start,int end){
    while(start<end){
        int Temp=arr[start];
        arr[start]=arr[end];
        arr[end]=Temp;
        start++;
        end--;
    }
}
void rotate(int arr[],int n,int k){
    if(n==0){
        return;
    }
    k=k%n;
    reverseList(arr,0,n-1);
    reverseList(arr,0,k-1);
    reverseList(arr,k,n-1);
}
void copyToarray(struct Node *head,int arr[]){
    int i=0;
    while(head!=NULL){
        arr[i++]=head->data;
        head=head->nxt;
    }
}
int displayList(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    struct Node *head=NULL;
    int n,i,data,arr[100],k;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter value of the %d node:",i);
        scanf("%d",&data);
        insertAtEnd(&head,data);
    }
    printf("Enter k value (step to rotate):");
    scanf("%d",&k);
    copyToarray(head,arr);
    rotate(arr,n,k);
    printf("Rotated arry:");
    displayList(arr,n);
}

