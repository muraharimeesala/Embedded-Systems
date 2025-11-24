#include<stdio.h>
int findMax(int arr[],int num){
int max=arr[0];
for(int i=0;i<num;i++){
if(arr[i]>max)
max=arr[i];
}
return max;
}
int findMin(int arr[],int num){
int min=arr[0];
for(int i=0;i<num;i++){
if(arr[i]<min)
min=arr[i];
}
return min;
}
int main(){
int numbers[]={10,12,15,4,1,23,15,79,45,99,100,56};
//printf("Enter array elements:");
//scanf("%d",numbers);
int num=sizeof(numbers)/sizeof(numbers[0]);
int (*Maxptr)(int arr[],int num)=findMax;
int (*Minptr)(int arr[],int num)=findMin;
int max=Maxptr(numbers,num);
int min=Minptr(numbers,num);
printf("Maximum is:%d\n",max);
printf("Minimum is:%d\n",min);
}



