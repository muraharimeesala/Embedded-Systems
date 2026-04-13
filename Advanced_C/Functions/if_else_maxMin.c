#include<stdio.h>
int checkMaxMin(int a,int b){
if(a>b){
printf("Maximum is:%d\n",a);  
printf("Minimum is:%d\n",b);
}
else
printf("Both are equal\n");
}
int main(){
int a,b;
printf("Enter a value:\n");
scanf("%d",&a);
printf("Enter b value:\n");
scanf("%d",&b);
checkMaxMin(a,b);
}
