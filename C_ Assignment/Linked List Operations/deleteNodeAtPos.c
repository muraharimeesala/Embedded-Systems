#include <stdio.h>
#include <stdlib.h>
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
void deleteNodeAtPos(struct Node **head, int pos){
	if (*head == NULL) {
		printf("List empty.\n");
		return;
	}
	struct Node *temp = *head;
	if (pos == 1) {
		*head = temp->nxt;
		free(temp);
		return;
	}
	for (int i = 1; i < pos - 1 && temp->nxt != NULL; i++)
		temp = temp->nxt;
	if (temp->nxt == NULL) {
		printf("Invalid position.\n");
		return;
	}
	struct Node *del = temp->nxt;
	temp->nxt = del->nxt;
	free(del);
}
void displayList(struct Node *head)
{
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->nxt;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int n, data, pos;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    printf("Enter %d nodes:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        addNodeAtEnd(&head,data);
    }
    printf("Original List: ");
    displayList(head);
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    deleteNodeAtPos(&head, pos);
    printf("Modified List: ");
    displayList(head);
    return 0;
}

