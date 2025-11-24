#include<stdio.h>
int main(){
int i,j,num,isPrime;
printf("Enter a number:");
scanf("%d",&num);
printf("Prime numbers between 1 to %d\n",num);
for(i=2;i<num;i++){
isPrime=1;
for(j=2;j*j<=i;j++){
if(i%j==0){
isPrime=0;
break;
}
}
if(isPrime){
printf("%d\n",i);
}
}
printf("\n");
}


