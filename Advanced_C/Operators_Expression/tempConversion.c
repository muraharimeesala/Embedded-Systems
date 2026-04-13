#include <stdio.h>

int main(){
	float c,f;
	printf("Enter the temperature in Celsius\n");
	scanf("%f",&c);
	f=(c*9)/5+32;
	printf("The temperature in Fahrenheit is %f\n",f);

	printf("Enter the temperature in Fahrenheit\n");
	scanf("%f",&f);
	c=(f-32)*5/9;
	printf("The temperature in Celsius is %f\n",c);
	return 0;
}
