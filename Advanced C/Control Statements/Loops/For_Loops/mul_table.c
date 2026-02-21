#include<stdio.h>
int main(){
int num,i,j;
printf("Enter a number:");
scanf("%d",num);
printf("Multiplication table from 1 to %d \n",num);
for(i=1;i<=10;i++){
   for(j=1;i<=num;j++){
      printf("%d X %d = %d\n",j,i,i*j);
}
printf("\n");
}
}
