#include<stdio.h>
#include<stdlib.h>
int main(){
int *ptr,num;
ptr=malloc(sizeof(int)*10);
printf("Enter no of elements:");
scanf("%d",&num);
for(int i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&ptr[i]);
}
int sum=0;
for(int i=0;i<num;i++){
printf("Value of pointer:%d Address of pointer:%p\n",ptr[i],&*(ptr+i));
sum+=ptr[i];
}
printf("Sum of elements:%d\n",sum);
free(ptr);
}
