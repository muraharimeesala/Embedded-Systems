#include<stdio.h>
int main(){
int arr[100],n,i;
int *p,*p1;
p=arr;
p1=&arr[3];
printf("Enter size of array:");
scanf("%d",&n);
printf("Enter %d Elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("After subtraction:\n");
if(p<p1){
printf("P1 is largest.\n");
}
else{
printf("P is largest.\n");
}
}

