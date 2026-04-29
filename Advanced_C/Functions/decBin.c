#include<stdio.h>
long toBin(int dno){
long bno=0,remainder,f=1;
while(dno!=0){
remainder=dno%2;
bno=bno+remainder*f;
f=f*10;
dno=dno/2;
}
return bno;
}
int main(){
int dno;
long bno;
printf("Enter decimal number:");
scanf("%d",&dno);
bno=toBin(dno);
printf("Binary value:%ld\n",bno);
}
