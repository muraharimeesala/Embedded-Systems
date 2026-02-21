#include<stdio.h>
int main(){
int numbers[10],max,i;
printf("Enter numbers[10]:");
for(i=0;i<10;i++){
scanf("%d",&numbers[i]);
}
for(i=0;i<10;i++)
if(numbers[i]>max)
max=numbers[i];
printf("The largest number:%d\n",max);
}

