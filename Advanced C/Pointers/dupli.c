#include<stdio.h>
int main(){
int num,i,j,count;
printf("Enter no of elements:");
scanf("%d",&num);
int arr[5];
for(i=0;i<5;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
for(i=0;i<5;i++){
for(j=i+1;j<num;j++){
if(arr[i]==arr[j]){
count++;
}
}
}
printf("%d",count);
}

