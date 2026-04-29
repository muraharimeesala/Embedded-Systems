#include<stdio.h>
int add(int x,int y){
int z;
z=x+y;
}
int main(){
int x=10,y=12,sum=0;
int (*addptr)(int x,int y);
addptr=add;
sum=addptr(x,y);
printf("Sum=%d\n",sum);
}

