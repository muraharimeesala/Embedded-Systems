#include<stdio.h>
int main(){
int n;
printf("Enter size of (n)x(n) matrix:");
scanf("%d",&n);
int n1[3][3],i,j,sum=0;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("Elements[%d][%d]:",i,j);
scanf("%d",&n1[i][j]);
}
}
printf("The sum of diagonal matrix of array:\n");
for(int i=0;i<n;i++){
sum+=n1[i][i];
}
printf("%d\n",sum);
}

