#include<stdio.h>
int main(){
int rows,cols,i,n,j,isSymmetric=1;
printf("Enter no of rows:");
scanf("%d",&rows);
printf("Enter no of cols:");
scanf("%d",&cols);
int arr[rows][cols];
printf("Enter %dx%d matrix:\n",rows,cols);
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){
scanf("%d",&arr[i][j]);
}
}
for(i=0;i<rows;i++){
for(j=0;j<cols;j++){
if(arr[i][j]!=arr[j][i]){
isSymmetric=0;
break;
}
}
if(!isSymmetric)
break;
}
if(isSymmetric)
printf("The matrix is symmetric.\n");
else
printf("The matrix is not symmetric.\n");
}
