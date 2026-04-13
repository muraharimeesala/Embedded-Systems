#include<stdio.h>

int tree[100];
int n;

void intialize()
{
    for(int i=0;i<n;i++)
    {
        tree[i]=-1;
    }
}

void insert(int data,int i)
{
    if(i==n)
    {
        printf("Tree is full\n");
        return;
    }
    tree[i]=data;
    i++;
    printf("Inserted %d\n",data);
}
void parent(int i){
    if(i==0){
        printf("No parent\n");
        return;
    }
    printf("Parent of %d is %d\n",tree[i],tree[(i-1)/2]);
}

void leftchild(int i){
    int l=2*i+1;
    if(l>=n){
        printf("No left child\n");
        return;
    }
    printf("Left child of %d is %d\n",tree[i],tree[l]);
}
void rightchild(int i){
    int r=2*i+2;
    if(r>=n){
        printf("No right child\n");
        return;
    }
    printf("Right child of %d is %d\n",tree[i],tree[r]);
}

int main(){
    int data,i;
    printf("Enter size of tree: ");
    scanf("%d",&n);
    printf("Enter %d Nodes:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insert(data,i);
    }
    printf("Enter index: ");
    scanf("%d",&i);
    parent(i);
    leftchild(i);
    rightchild(i);
    return 0;
}
