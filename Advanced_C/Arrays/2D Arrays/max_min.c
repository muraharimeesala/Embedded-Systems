#include<stdio.h>
int main(){
int arr[2][3],i,j;
printf("Enter the elements of matrix:\n");
for(int i=0;i<2;i++){
for(int j=0;j<3;j++){
printf("Element [%d][%d]:",i,j);
scanf("%d",&arr[i][j]);
}
}
int max=arr[0][0];
int min=arr[0][0];
for(int i=0;i<2;i++){
for(int j=0;j<3;j++){
if(arr[i][j]>max){
max=arr[i][j];
}
if(arr[i][j]<min){
min=arr[i][j];
}
}
}
printf("Maximum is:%d\n",max);
printf("Minimum is:%d\n",min);
}


