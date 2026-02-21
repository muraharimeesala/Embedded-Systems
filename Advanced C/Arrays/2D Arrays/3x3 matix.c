#include<stdio.h>
int main(){
int n1[3][3],i,j;
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("Elements[%d][%d]:",i,j);
scanf("%d",&n1[i][j]);
}
}
printf("The matrix of array:\n");
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("%d\t",n1[i][j]);
}
printf("\n");
}
}
