#include<stdio.h>
#include<stdlib.h>
int main(){
int row,colm,i,j;
int *ptr;
printf("Enter no of rows:");
scanf("%d",&row);
printf("Enter no of columns:");
scanf("%d",&colm);
ptr=malloc(sizeof(int)*row*colm);    //Allocate a block memory for all elements
printf("2D array using single pointer:\n");
for(i=0;i<row;i++){
for(j=0;j<colm;j++){
*(ptr+i*colm+j)=i+j;
printf("%d ",*(ptr+i*colm+j));
}
printf("\n");
}
free(ptr);
}
