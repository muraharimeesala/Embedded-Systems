#include<stdio.h>
int main(){
int num[100],i,n;
int *ptr;
ptr=num;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&num[i]);
}
for(i=n;i>0;i--){
printf("%d ",ptr[i]);
}
}

