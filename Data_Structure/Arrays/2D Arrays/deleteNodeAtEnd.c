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
    pnew->next = NULL;
    pnew->prev = NULL;
  }
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = pnew;
  pnew->prev = temp;
}

void deleteNodeAtEnd(struct node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct node *temp = *head;

  if (temp->next == NULL) { // only one node
    free(temp);
    *head = NULL;
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->prev->next = NULL;
  free(temp);
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
    printf("Enter Data For %d Node: ", i + 1);
    scanf("%d", &data);
    addNodeAtEnd(&head, data);
  }
  printf("Orginal List: ");
  display(head);
  deleteNodeAtEnd(&head);
  printf("Deleted List: ");
  display(head);
  return 0;
}
