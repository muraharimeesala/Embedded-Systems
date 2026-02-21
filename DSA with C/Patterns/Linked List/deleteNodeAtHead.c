#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *nxt;
};
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *pnew;
struct Node *createNodes(int data){
        pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Error.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
        pnew=createNodes(data);
        temp=*head;
        if(*head==NULL){
                *head=pnew;
                return;
        }
        while(temp->nxt!=NULL){
                temp=temp->nxt;
        }
        temp->nxt=pnew;
}
void deleteNodeAtHead(struct Node **head) {
    if (*head==NULL) {
        printf("List is empty.\n");
        return;
    }
    temp=*head;        // store old head
    *head=temp->nxt;   // move head to next node
    free(temp);          // free old head
}
void displayList(struct Node *head) {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    while(head!=NULL) {
        printf("%d ->",head->data);
        head=head->nxt;
    }
    printf("NULL\n");
}
int main(){
    int n,i,data,pos;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for (i=0;i<n;i++) {
        scanf("%d",&data);
        addNodeAtEnd(&head,data);  // insert at end
    }
    printf("Original List: ");
    displayList(head);
    deleteNodeAtHead(&head);
    printf("Updated List:\n");
    displayList(head);
}

