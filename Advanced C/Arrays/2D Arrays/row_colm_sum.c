#include<stdio.h>
int main(){
int num[10][10],i,j,row_sum=0,coloum_sum=0,n;
printf("Enter size of 2d array:");
scanf("%d",&n);
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("Element[%d][%d]:",i,j);
scanf("%d",&num[i][j]);
}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%d\t",num[i][j]);
row_sum=row_sum+num[i][j];
coloum_sum=coloum_sum+num[i][j];
}
printf("\n");
}
printf("Sum=%d\n",row_sum);
printf("Sum=%d\n",coloum_sum);
}
