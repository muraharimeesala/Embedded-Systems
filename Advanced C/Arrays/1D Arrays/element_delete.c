#include<stdio.h>
int main(){
int arr[100],num,pos,i;
printf("Enter no of elements:");
scanf("%d",&num);
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
printf("Enter position of element to delete:",num);
scanf("%d",&pos);
if(pos<1 || pos>num){
printf("Invalid Position:\n");
}
else{
for(i=pos-1;i<num-1;i++){
arr[i]=arr[i+1];
}
num--;
}
printf("Array after deletion:\n");
for(i=0;i<num;i++){
printf("%d\n",arr[i]);
}
}
