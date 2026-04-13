#include<stdio.h>
int Table(int num){
for(int i=1;i<=10;i++){
printf("%d x %d =%d\n",i,num,i*num);
}
}
int main(){
int num;
printf("Enter a number:");
scanf("%d",&num);
Table(num);
}
