#include<stdio.h>
int main(){
int arr[2][3][4],i,j,k;
printf("Enter the 3d array elements:\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
for(k=0;k<4;k++){
printf("Elements [%d][%d][%d]:",i,j,k);
scanf("%d",&arr[i][j][k]);
}
}
}
printf("3d Array elements:\n");
for(i=0;i<2;i++){
printf("Block %d:\n",i);
for(j=0;j<3;j++){
for(k=0;k<4;k++){
printf("%d ",arr[i][j][k]);
}
printf("\n");
}
printf("\n");
}
}
