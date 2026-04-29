#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 100

int n,arr[SIZE];
int first=-1,last=-1;
int value;
void enqueue(){
    if(last==SIZE-1){
        printf("Queue OverFlow\n");
        exit(1);
    }
    else{
        if(first==-1){
            first=0;
        }
        last++;
        arr[last]=value;
        printf("Inserted : %d\n",value);
    }
}
void display(){
    if(first==-1){
        printf("Queue is empty\n");
        exit(1);
    }
    printf("Queue Elements:\n");
    for(int i=first;i<=last;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    printf("Enter size of queue:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enqueue();
    }
    display();
}

