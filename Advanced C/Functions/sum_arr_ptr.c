#include<stdio.h>
int Sum(int *arr,int size){
int sum=0;
for(int i=0;i<size;i++){
sum+=arr[i];
}
return sum;
}
int main(){
int num[]={10,20,30,40,50};
int size=sizeof(num)/sizeof(num[0]);
int total=Sum(num,size);
printf("Sum=%d\",total);
}
