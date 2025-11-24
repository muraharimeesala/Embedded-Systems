#include<stdio.h>
int main(){
int num,i,sum=0;
float avg;
printf("Enter the 10 numbers:");
for(i=0;i<=10;i++){
printf("Number-%d:",i);
scanf("%d",&num);
sum+=num;
}
printf("The sum of 10 numbers is:%d\n",sum);
avg=sum/10.0;
printf("The average is :%f\n",avg);
}
