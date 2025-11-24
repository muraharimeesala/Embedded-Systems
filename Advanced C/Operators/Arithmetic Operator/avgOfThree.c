#include<stdio.h>
int main(){
	int a,b,c;
	float avg;
	printf("Enter A and B and C values:");
	scanf("%d %d %d",&a,&b,&c);
	avg=(a+b+c)/3.0;
	printf("Avg of three numbers:%.2f\n",avg);
}
