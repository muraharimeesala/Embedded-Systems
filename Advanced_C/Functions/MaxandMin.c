#include<stdio.h>
int MaxorMin(int,int); 
int main(){
int a=10,b=12;
//printf("Enter two numbers:");
//scanf("%d%d",&a,&b);
MaxorMin(10,12);
MaxorMin(12,10);
MaxorMin(10,10);
}
int MaxorMin(int a,int b)
if(a>b){
printf("A is Maximum\n");
printf("B is Minimum\n");
}
else{
printf("B is Maximum\n");
printf("A is Minimum\n");
}
}
