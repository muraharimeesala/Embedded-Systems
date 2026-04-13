// Write a program to search a value in a binary array tree.

#include<stdio.h>

#define SIZE 10

int tree[SIZE] = {10,20,30,40,50};

void search(int key)
{
    for(int i=0;i<SIZE;i++)
    {
        if(tree[i] == key)
        {
            printf("Element found at index %d\n",i);
            return;
        }
    }

    printf("Element not found\n");
}

int main()
{
    int key;

    printf("Enter element to search: ");
    scanf("%d",&key);

    search(key);

    return 0;
}
