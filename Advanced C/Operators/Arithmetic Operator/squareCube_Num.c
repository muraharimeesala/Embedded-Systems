#include<stdio.h>
#include<math.h>
int main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	int square=(int)pow(n,2);
	int cube=(int)pow(n,3);
	printf("Square is:%d\n",square);
	printf("Cube is:%d\n",cube);
}
