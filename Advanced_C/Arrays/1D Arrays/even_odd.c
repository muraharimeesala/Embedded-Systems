#include<stdio.h>
int main(){
int num,i;
printf("Enter array elements:");
scanf("%d",&num);
int arr[100];
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
printf("Even numbers are:\n");
for(i=0;i<num;i++){
if(arr[i]%2==0){
int Even=arr[i];
printf("%d\n",Even);
//printf("%d\n",arr[i]);
}
}
printf("Odd numbers are:\n");
for(i=0;i<num;i++){
if(arr[i]%2!=0){
int Odd=arr[i];
printf("%d\n",Odd);
//printf("%d\n",arr[i]);
}
}
printf("\n");
}

