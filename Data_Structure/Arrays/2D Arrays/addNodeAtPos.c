#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *temp = NULL;
struct node *pnew;

struct node *createnode(int data) {
  pnew = (struct node *)malloc(sizeof(struct node));
  if (pnew == NULL) {
    printf("Memory not allocated");
    exit(1);
  }
  pnew->data = data;
  pnew->next = NULL;
  pnew->prev = NULL;
  return pnew;
}

void addNodeAtEnd(struct node **head, int data) {
  pnew = createnode(data);
  if (*head == NULL) {
    *head = pnew;
    (*head)->next = NULL;
    (*head)->prev = NULL;
    return;
  }
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = pnew;
  pnew->prev = temp;
  pnew->next = NULL;
}

void addNodeAtPos(struct node **head, int data, int pos) {
  pnew = createnode(data);
  if (pos == 1) {
    pnew->next = *head;
    (*head)->prev = pnew;
    *head = pnew;
    return;
  }
  temp = *head;
  int i = 1;
  for (i = 1; i <= pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Position not found");
    exit(1);
  }
  if (temp->next == NULL) {
    temp->next = pnew;
    pnew->prev = temp;
    return;
  }
  pnew->next = temp->next;
  // pnew->prev = temp;
  temp->next->prev = pnew;
  // temp->next = pnew;
}
void display(struct node *head) {
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int n, data, pos, i;
  printf("Enter Size: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter Data For %d Node: ", i + 1);
    scanf("%d", &data);
    addNodeAtEnd(&head, data);
  }
  printf("Original List: ");
  display(head);
  printf("Enter Position: ");
  scanf("%d", &pos);
  printf("Enter Data: ");
  scanf("%d", &data);
  addNodeAtPos(&head, data, pos);
  printf("Modified List: ");
  display(head);
  return 0;
}
