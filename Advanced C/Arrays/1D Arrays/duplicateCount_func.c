#include<stdio.h>
int duplicateCount(int arr[],int n){
int count=0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(arr[i]==arr[j]){
count++;
break;
}
}
}
return count;
}
int main(){
int n,arr[100],i,j,count=0;
printf("Enter elements of array:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
count=duplicateCount(arr,n);
printf("The duplicate values of array are:%d\n",count);
}

