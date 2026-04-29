#include<stdio.h>
#include<stdlib.h>
int main(){
int row,colm,i,j;
int **ptr;
printf("Enter no of rows:");
scanf("%d",&row);
printf("Enter no of columns:");
scanf("%d",&colm);
ptr=malloc(sizeof(int)*row);     //Allocate memory for row pointer
for(i=0;i<row;i++){
ptr[i]=malloc(sizeof(int)*colm);   // Allocate memory for each row
}
printf("Enter elements:\n");
for(i=0;i<row;i++){
for(j=0;j<colm;j++){
ptr[i][j]=i+j;
printf("%d ",ptr[i][j]);
}
printf("\n");
}
for(i=0;i<row;i++){
free(ptr[i]);
}
free(ptr);
}
