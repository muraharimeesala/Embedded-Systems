#include<stdio.h>
int main(){
int a,b;
printf("Enter Two Values:");
scanf("%d%d",&a,&b);
if(a>b){
printf("%d is Maximum\n",a);
printf("%d is Minimum\n",b);
}
else{
printf("%d is Maximum\n",b);
printf("%d is Minimum\n",a);
}
}
