#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Traversals
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
// Queue for Level Order
#define SIZE 100
struct Queue {
    struct TreeNode* arr[SIZE];
    int front, rear;
};
void initQueue(struct Queue* q) { q->front = q->rear = -1; }
int isEmpty(struct Queue* q) { return q->front == -1; }
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (q->rear == SIZE - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}
struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct TreeNode* temp = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return temp;
}
void levelOrder(struct TreeNode* root) {
    if (root == NULL) return;
    struct Queue q; initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        struct TreeNode* node = dequeue(&q);
        printf("%d ", node->data);
        if (node->left) enqueue(&q, node->left);
        if (node->right) enqueue(&q, node->right);
    }
}

int main() {
    // Build sample tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");

    return 0;
}

