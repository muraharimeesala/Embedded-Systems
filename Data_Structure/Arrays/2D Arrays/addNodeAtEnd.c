#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *prev;
  struct node *next;
};
struct node *head = NULL;
struct node *temp = NULL;
struct node *pnew;

struct node *createnode(int data) {
  pnew = (struct node *)malloc(sizeof(struct node));
  pnew->data = data;
  pnew->prev = NULL;
  pnew->next = NULL;
  return pnew;
}

void addNodeAtEnd(struct node **head, int data) {
  pnew = createnode(data);
  if (*head == NULL) {
    *head = pnew;
    pnew->next = NULL;
    pnew->prev = NULL;
  }
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = pnew;
  pnew->prev = temp;
  pnew->next = NULL;
}
void display(struct node *head) {
  temp = head;
  if (temp == NULL) {
    printf("No nodes in the list");
  }
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int main() {
  int n, data, i;
  printf("Enter Size: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter Data for %d node: ", i + 1);
    scanf("%d", &data);
    addNodeAtEnd(&head, data);
  }
  printf("Original List: ");
  display(head);
  printf("Enter Data For End Node: ");
  scanf("%d", &data);
  addNodeAtEnd(&head, data);
  printf("Modified List: ");
  display(head);
  return 0;
}
