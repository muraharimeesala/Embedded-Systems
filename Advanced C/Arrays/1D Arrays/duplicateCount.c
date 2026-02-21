#include<stdio.h>
int main(){
int num,arr[100],i,j,count=0;
printf("Enter elements of array:");
scanf("%d",&num);
for(i=0;i<num;i++){
printf("Element %d:",i);
scanf("%d",&arr[i]);
}
for(i=0;i<num;i++){
for(j=i+1;j<num;j++){
if(arr[i]==arr[j]){
count++;
break;
}
}
}
printf("The duplicate values of array are:%d\n",count);
}

