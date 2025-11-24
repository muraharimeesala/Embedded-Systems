#include<stdio.h>
int main(){
	int hours,minutes,min;
	printf("Enter minutes:");
	scanf("%d",&minutes);
	hours=minutes/60;
	min=minutes%60;
	printf("%d Minutes=%d houres %d minutes.\n",minutes,hours,min);
}
