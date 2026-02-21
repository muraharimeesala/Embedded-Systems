#include<stdio.h>
int main(){
int num,i;
printf("Enter the number of elements:");
scanf("%d",&num);
int arr[num],even[num],odd[num];
int evenCount=0,oddCount=0;
printf("Enter %d integers:\n",num);
for(i=0;i<num;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<num;i++){
if(arr[i]%2==0){
even[evenCount++]=arr[i];
}
else{
odd[oddCount++]=arr[i];
}
}
printf("Even numbers:\n");
for(i=0;i<evenCount;i++){
printf("%d\n",even[i]);
}
printf("Odd numbers:\n");
for(i=0;i<oddCount;i++){
printf("%d\n",odd[i]);
}
}
