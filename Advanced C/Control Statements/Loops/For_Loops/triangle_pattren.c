#include<stdio.h>
int main(){
int i,j,rows,k=1;
printf("Enter no of rows:");
scanf("%d",&rows);
for(i=1;i<=rows;i++){
for(j=1;j<=i;j++)
//printf("*\t",i,j);
//printf("*",i,j);
//printf("%d",i,j);
printf("%d",k++); 
printf("\n");
}
}

