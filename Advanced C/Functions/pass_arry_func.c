#include<stdio.h>
int Sum(int arr[],int size){
int sum=0;
for(int i=0;i<size;i++){
sum+=arr[i];
}
return sum;
}
int main(){ 
int array[]={10,20,30,40,50,60};
int size=sizeof(array)/sizeof(array[0]);
int total=Sum(array,size);
printf("Sum=%d",total);
}

