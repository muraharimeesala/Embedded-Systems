#include<stdio.h>
int main(){
int arr[10][10],n,i,j,sum=0;
printf("Enter size of (n) x (n) matrix:");
scanf("%d",&n);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("Element[%d[%d]:",i,j);
scanf("%d",&arr[i][j]);
}
}
printf("Sum of right diagonal of the matrix:");
for(i=0;i<n;i++){
sum+=arr[i][n-1-i];
}
printf("%d\n",sum);
}

