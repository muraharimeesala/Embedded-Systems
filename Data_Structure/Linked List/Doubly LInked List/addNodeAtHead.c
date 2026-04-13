#include <stdio.h>
#include <stdlib.h> // for malloc(sizeof(

struct node {
  int data;
  struct node *prev;
  struct node *nxt;
};

struct node *pnew = NULL;
struct node *head = NULL;
struct node *temp = NULL;
struct node *createnode(int data) {
  pnew = (struct node *)malloc(sizeof(struct node));
  if (pnew == NULL) {
    printf("Memory not allocated");
    exit(1);
  }
  pnew->data = data;
  pnew->prev = NULL;
  pnew->nxt = NULL;
  return pnew;
}
void CurrentList() {
  int data;
  pnew = createnode(data);
  temp = head;
  if (temp == NULL) {
    head = pnew;
    return;
  }
  while (temp->nxt != NULL) {
    temp = temp->nxt;
  }
  temp->nxt = pnew;
}

void addNodeAtHead() {
  temp = head;
  if (head == NULL) {
    printf("List is empty");
    return;
  }
  pnew->nxt = head;
  head = pnew;
}

void displayList() {
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->nxt;
  }
  printf("\n");
}
int main() {
  int n, data, i;
  printf("Enter Size: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter Data for node %d: ", i);
    scanf("%d", &data);
    CurrentList();
  }
  printf("Original List: ");
  displayList();
  printf("Enter Data to be added: ");
  scanf("%d", &data);
  addNodeAtHead();
  displayList();
  return 0;
}
