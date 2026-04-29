#include<stdio.h>
int main(){
int num,i;
printf("Enter no of elements:");
scanf("%d",&num);
int arr[100];
int *ptr;
ptr=arr;
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
for(i=0;i<num;i++){
printf("%d ",*ptr);
printf("%p\n",&*ptr);
//printf("%d ",ptr[i]);
//printf("%p\n",&ptr[i]);
//printf("%d ",*(ptr+i));
//printf("%p\n",&*(ptr+i));
//printf("%d ",i[ptr]);
//printf("%p\n",&i[ptr]);
//printf("%d ",*(i+ptr));
//printf("%p\n",&*(i+ptr));
}
}
