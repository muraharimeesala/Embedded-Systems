#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *nxt;
};
struct Node *createNodes(int data){
        struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
        if(pnew==NULL){
                printf("Memory Error.\n");
                exit(1);
        }
        pnew->data=data;
        pnew->nxt=NULL;
        return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
       struct Node *pnew=createNodes(data);
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
void insertAtPos(struct Node **head,int data,int pos){
        struct Node *pnew=createNodes(data);
        struct Node *temp=*head;
        if(pos==0){
                pnew->nxt=*head;
                *head=pnew;
                return;
        }
        for(int i=0;i<pos-1&&temp!=NULL;i++){
                temp=temp->nxt;
        }
        pnew->nxt=temp->nxt;
        temp->nxt=pnew;
}
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->nxt;
    }
    printf("NULL\n");
}
int main() {
    int n, i, data, pos;
    struct Node *head = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        addNodeAtEnd(&head,data);  // insert at end
    }
    printf("Original List: ");
    display(head);
    printf("Enter value to insert: ");
    scanf("%d", &data);
    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);
    insertAtPos(&head, data, pos);
    printf("Updated List: ");
    display(head);
    return 0;
}

