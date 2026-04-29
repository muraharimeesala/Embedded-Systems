#include<stdio.h>
int max(int a,int b,int c){
int largest=a;
if(b>largest) largest=b;
if(c>largest) largest=c;
return largest;
}
int main(){
int a=9,b=11,c=12;
int result=max(a,b,c);
printf("Maximum is:%d\n",result);
}
