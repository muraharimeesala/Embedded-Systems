#include<stdio.h>

#define SIZE 5

int tree[SIZE];

int initialize()
{
    for(int i=0;i<SIZE;i++)
    {
        tree[i]=-1;
    }
    return 0;
}

void insert(int data,int i){
    if(i==SIZE)
    {
        printf("Tree is full\n");
        return;
    }
    tree[i]=data;
    i++;
    printf("%d inserted\n",data);
}

void display(){
    if(tree[0]==-1)
    {
        printf("Tree is empty\n");
        return;
    }
    for(int i=0;i<SIZE;i++){
        if(tree[i]!=-1)
        {
            printf("Index %d: Value %d\n",i,tree[i]);
        }
    }
}

int main(){
    int n,data,i;
    printf("Enter size of tree: ");
    scanf("%d",&n);
    printf("Enter %d Nodes:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        insert(data,i);
    }
    printf("Tree:\n");
    display();
    return 0;
    }
