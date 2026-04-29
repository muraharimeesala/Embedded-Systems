#include<stdio.h>
int reverseNum(int num){
int rev=0;
while(num!=0){
int digit=num%10;
rev=rev*10+digit;
num/=10;
}
return rev;
}
int main(){
int num=12345;
printf("Before reverse of number:%d\n",num);
int rev=reverseNum(num);
printf("After reverse of number:%d\n",rev);
}
