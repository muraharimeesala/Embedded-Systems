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
    printf("Memory not Allocated");
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
    pnew->prev = NULL;
    pnew->next = NULL;
    return;
  }
  temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = pnew;
  pnew->prev = temp;
}

void deleteNodeAtHead(struct node **head) {
  if (*head == NULL) {
    printf("List is Empty");
    exit(1);
  }
  temp = *head;
  ;
  *head = temp->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
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
  printf("Original List: ");
  display(head);
  deleteNodeAtHead(&head);
  printf("Deleted List: ");
  display(head);
  return 0;
}
