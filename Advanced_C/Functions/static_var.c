#include<stdio.h>
int x=10;
int b;
int func();
int main(){
func();
func();
func();
}
int func(){
int a=10;
static int b=20;
printf("%d\n%d\n",a,b);
a++;
b++;
}
