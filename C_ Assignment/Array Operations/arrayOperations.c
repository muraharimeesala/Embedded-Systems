#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 100
int arr[SIZE];
int n;

void insertAtBegin(){
    int value;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    for(int i = n-1; i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    n++;
    printf("%d Value Inserted At Begining\n",value);
}

void insertAtEnd(){
    int value;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    arr[n-1] = value;
    n++;
    printf("%d Value Inserted At End\n",value);
}

void insertAtIndex(){
    int value,index;
    printf("Enter value to insert: ");
    scanf("%d",&value);
    printf("Enter index: ");
    scanf("%d",&index);
    if(index<0 || index>n){
        printf("Invalid Index\n");
        return;
    }
    for(int i = n-1; i>index;i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    n++;
    printf("%d Value Inserted At Index %d\n",value,index);
}

void deleteAtBegin(){
    if(n==0){
        printf("Array is Empty\n");
        return;
    }
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    n--;
    printf("%d Value Deleted At Begining\n",arr[0]);
}

void deleteAtEnd(){
    if(n==0){
        printf("Array is Empty\n");
        return;
    }
    n--;
    printf("%d Value Deleted At End\n",arr[n-1]);
}

void deleteAtIndex(){
    int index;
    printf("Enter index: ");
    scanf("%d",&index);
    if(index<0 || index>=n){
        printf("Invalid Index\n");
        return;
    }
    for(int i=index;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    n--;
    printf("%d Value Deleted At Index %d\n",arr[index],index);
}

void display(){
    if(n==0){
        printf("Array is Empty\n");
        return;
    }
    printf("Array Elements: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int i,value,index;
    printf("Enter Size Of Array: ");
    scanf("%d",&n);
    printf("Enter %d Array Elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ch;
    while(1){
        printf("\n1.Insert At Begin\n2.Insert At End\n3.Insert At Index\n4.Delete At Begin\n5.Delete At End\n6.Delete At Index\n7.Display\n8.Exit\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insertAtBegin();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtIndex();
                break;
            case 4:
                deleteAtBegin();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtIndex();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
        }
    }
    return 0;
}
