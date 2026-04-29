#include<stdio.h>
int main(){
int rows,colms,i,j;
printf("Enter no of rows of matrix:");
scanf("%d",&rows);
printf("Enter no of columns of matrix:");
scanf("%d",&colms);
int mat[rows][colms];
for(i=0;i<rows;i++){
for(j=0;j<colms;j++){
printf("Element-[%d][%d]:",i,j);
scanf("%d",&mat[i][j]);
}
}
printf("Lower triangular matrix:\n");
for(i=0;i<rows;i++){
for(j=0;j<colms;j++){
if(i<j){
printf("0\t");
}
else
printf("%d\t",mat[i][j]);
}
printf("\n");
}
}
