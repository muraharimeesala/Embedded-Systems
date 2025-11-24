#include<stdio.h>
int printEven(int start,int end){
printf("Even numbers between %d and %d is:\n",start,end);
while(start<=end){
if(start%2==0){
printf("%d\n",start);
}
start++;
}
printf("\n");
}
int printOdd(int start,int end){
printf("Odd numbers between %d and %d is:\n",start,end);
while(start<=end){
if(start%2!=0){
printf("%d\n",start);
}
start++;
}
printf("\n");
}
int main(){
int startRange,endRange;
printf("Enter the starting number of the range:");
scanf("%d",&startRange);
printf("Enter the ending number of the range:");
scanf("%d",&endRange);
printEven(startRange,endRange);
printOdd(startRange,endRange);
}




