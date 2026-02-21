#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *nxt;
    struct Node *prev;
};
/* Insert node at beginning */
void insertAtBeginning(struct Node **head,int data) {
    struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
    if(pnew==NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    pnew->data=data;
    pnew->prev=NULL;
    pnew->nxt=*head;
    if(*head!=NULL) {
        (*head)->prev=pnew;
    }
    *head=pnew;
}
/* Display list */
void displayList(struct Node *head) {
    if(head==NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp=head;
    while (temp!=NULL) {
        printf("%d<->",temp->data);
        temp=temp->nxt;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head=NULL;
    int n,i,data,newData;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter %d node values:\n",n);
    for (i=0;i<n;i++){
        scanf("%d",&data);
        insertAtBeginning(&head,data);
    }
    printf("\nOriginal List:\n");
    displayList(head);
    printf("\nEnter value to insert at beginning: ");
    scanf("%d",&newData);
    insertAtBeginning(&head,newData);
    printf("\nUpdated List:\n");
    displayList(head);
    return 0;
}

