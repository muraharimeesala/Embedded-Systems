#include<stdio.h>
void fun(int* x,int* y);
void main(){
int x=5,y=7;
fun(&x,&y);
printf("x=%d y=%d\n",x,y);
}
void fun(int* x,int* y){
*x=7;
*y=5;
printf("x=%d y=%d\n",*x,*y);
}


