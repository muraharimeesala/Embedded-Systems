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
struct node prev;

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
  temp = *head;
  pnew = createnode(data);
  if (*head == NULL) {
    *head = pnew;
    pnew->next = NULL;
    return;
  }
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = pnew;
  pnew->next = NULL;
}

void addNodeAtHead(struct node **head, int data) {
  pnew = createnode(data);
  if (*head == NULL) {
    printf("List is empty");
    exit(1);
  }
  temp = *head;
  pnew->next = temp;
  temp->prev = pnew;
  *head = pnew;
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
  int n, data, i;
  printf("Enter Size: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter Data of %d node: ", i + 1);
    scanf("%d", &data);
    addNodeAtEnd(&head, data);
  }
  printf("Original List: ");
  display(head);
  printf("Enter Data of Head node: ");
  scanf("%d", &data);
  addNodeAtHead(&head, data);
  printf("Modified List: ");
  display(head);
  return 0;
}
