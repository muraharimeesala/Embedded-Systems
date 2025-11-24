#include<stdio.h>
int main(){
	float c,f;
	printf("Enter a temp in celsius:");
	scanf("%f",&c);
	printf("Enter a temp in fahrenheit:");
	scanf("%f",&f);
	f=(c+9/5)+32;
	c=(f-32)*5/9;
	printf("Temp in Fahrenheit:%.2f\n",f);
	printf("Temp in Celsius:%.2f\n",c);
}
