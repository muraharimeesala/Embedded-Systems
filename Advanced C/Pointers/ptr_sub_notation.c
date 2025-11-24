#include<stdio.h>
int main(){
int arr[100],n,i;
int *ptr;
ptr=arr;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Accessing array elements using pointer notation:\n");
for(i=0;i<n;i++){
printf("*(ptr+%d)=%d\n",i,*(ptr+i));
}
printf("Accessing array elements using subcript notation:\n");
for(i=0;i<n;i++){
printf("ptr[%d]=%d\n",i,ptr[i]);
}
}
