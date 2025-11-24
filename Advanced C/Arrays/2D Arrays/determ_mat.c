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
int a=mat[rows][colms];
int b=mat[rows][colms];
int c=mat[rows][colms];
int d=mat[rows][colms];
int e=mat[rows][colms];
int f=mat[rows][colms];
int g=mat[rows][colms];
int h=mat[rows][colms];
int i_=mat[rows][colms];
int determ=a*(e*i_-h*f)-b*(d*i_-g*f)+c*(d*h-e*g);
printf("Determination of matrix:%d\n",determ);
}
