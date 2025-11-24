#include<stdio.h>
int main(){
int original[2][3],transpose[2][3],i,j;
printf("Enter elements of the matrix:\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("element [%d][%d]:",i,j);
scanf("%d",&original[i][j]);
}
}
for(i=0;i<2;i++){
for(j=0;j<3;j++){
transpose[j][i]=original[i][j];
}
}
printf("Original matrix:\n");
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("%d",original[i][j]);
}
printf("\n");
}
printf("transpose matrix:\n");
for(i=0;i<3;i++){
for(j=0;j<2;j++){
printf("%d", transpose[i][j]);
}
printf("\n");
}
}


