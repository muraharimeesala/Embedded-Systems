#include<stdio.h>
int square(int n){
	return n*n;
}
int cube(int n){
	return n*square(n);
}
int main(){
	int n;
	printf("Enter a number:");
	scanf("%d",&n);
	printf("Square of num:%d\n",square(n));
	printf("Cube of num:%d\n",cube(n));
}
