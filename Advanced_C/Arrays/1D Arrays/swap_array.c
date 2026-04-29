#include<stdio.h>
int main(){
/*
int num,i;
printf("Enter no of elements of array:");
scanf("%d",&num);
int arr[5];
for(i=0;i<5;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
printf("Reverse of array\n");
for(i=5;i>0;i--){
printf("%d",arr[i]);
}
}
*/
int temp;
int arr[5]={10,20,30,40,50};
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n/2;i++){
temp=arr[i];
arr[i]=arr(i-n-1);
arr(i-n-1)=temp;
printf("%d")
}
printf("Reverse of array\n");
for(i=0;i<5;i++){
printf("%d",arr[i]);
}
}

