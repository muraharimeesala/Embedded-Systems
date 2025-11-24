#include<stdio.h>
int checkEven(int arr[],int size);
int main(){
int arr[5],i;
int num;
printf("Enter array elements:");
scanf("%d",&num);
for(int i=0;i<5;i++){
printf("Elements [%d]:",i);
scanf("%d",&arr[i]);
}
checkEven(arr,num);
}
int checkEven(int arr[],int size){
for(int i=0;i<5;i++){
if(arr[i]%2==0){
printf("%d Even\n",arr[i]);
}
else{
printf("%d Odd\n",arr[i]);
}
}
printf("\n");
}
