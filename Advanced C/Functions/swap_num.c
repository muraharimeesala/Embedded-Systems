#include<stdio.h>
int swapNum(int *num1,int *num2){
int temp;
temp=*num1;
*num1=*num2;
*num2=temp;
}
int main(){
int num1=5,num2=7;
printf("Before swapping:\nnum1=%d num2=%d\n",num1,num2);
swapNum(&num1,&num2);
printf("After swapping:\nnum1=%d num2=%d\n",num1,num2);
}


