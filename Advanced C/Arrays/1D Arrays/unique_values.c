#include<stdio.h>
int main(){
int num,i,j;
int arr[100],count=0;
printf("Enter a array elements:");
scanf("%d",&num);
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
printf("The unique elements of array:\n");
for(i=0;i<num;i++){
count=0;
for(j=0;j<num;j++){
if(arr[i]==arr[j])
count++;
}
if(count==1){
printf("%d",arr[i]);
}
}
printf("\n");
}
