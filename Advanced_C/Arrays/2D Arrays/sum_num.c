#include<stdio.h>
int main(){
int num[2][3],i,j,sum=0;
printf("Enter 2D array elements:");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
scanf("%d",&num[i][j]);
}
}
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%d\t",num[i][j]);
sum=sum+num[i][j];
}
printf("\n");
}
printf("Sum=%d\n",sum);
}
