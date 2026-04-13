#include<stdio.h>
int main(){
int num,arr[100],i,j,count=0;
int k;
printf("Enter elements of array:");
scanf("%d",&num);
for(i=0;i<num;i++){
printf("Element %d:",i);
scanf("%d",&arr[i]);
}
for(i=0;i<num;i++){
for(j=i+1;j<num;j++){
if(arr[i]==arr[j]){
arr[k]=count++;
break;
}
}
}
for(i=0;i<num;i++){

printf("The duplicate values of array are:%d\n",arr[k]);
}
}

