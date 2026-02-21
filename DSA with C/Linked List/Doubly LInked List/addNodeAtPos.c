#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
/* Create a new node */
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/* Insert at given position */
void insertAtPosition(struct Node **head, int data, int pos) {
    struct Node *newNode = createNode(data);
    /* Insert at beginning */
    if (pos == 1) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    int i;
    /* Traverse to (pos - 1)th node */
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    /* Insert in middle or end */
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}
/* Display list */
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
/* Main function */
int main() {
    struct Node *head = NULL;
    int n, data, pos;
    printf("Enter no of nodes:");
    scanf("%d", &n);
    printf("Enter %d nodes:\n",n);
    for (int i=1;i<=n;i++) {
        scanf("%d", &data);
        insertAtPosition(&head, data, i);  // insert sequentially
    }
    printf("\nCurrent List:\n");
    display(head);
    printf("\nEnter data to insert: ");
    scanf("%d", &data);
    printf("Enter position: ");
    scanf("%d", &pos);
    insertAtPosition(&head, data, pos);
    printf("\nList after insertion:\n");
    display(head);
    return 0;
}

