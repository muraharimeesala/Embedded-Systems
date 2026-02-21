#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
void createNode(struct Node **head,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Error.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
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
int compareLists(struct Node *list1, struct Node *list2){
    	while (list1 != NULL && list2 != NULL){
		if (list1->data != list2->data)
		    	return 0;  
		list1 = list1->nxt;
	       	list2 = list2->nxt;
	}
	// Both must end at NULL
	if (list1 == NULL && list2 == NULL)
		return 1;   // Equal
	else
		return 0;   // Length mismatch
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int n1, n2, data, i;
    printf("LIST1: Enter number of nodes: ");
    scanf("%d", &n1);
    printf("Enter %d nodes:\n", n1);
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &data);
        createNode(&list1, data);
    }
    printf("LIST2: Enter number of nodes: ");
    scanf("%d", &n2);
    printf("Enter %d nodes:\n", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &data);
        createNode(&list2, data);
    }
    printf("LIST1: ");
    displayList(list1);
    printf("LIST2: ");
    displayList(list2);
    if (compareLists(list1, list2))
        printf("Both the lists are equal.\n");
    else
        printf("Both the lists are not equal.\n");
    return 0;
}
