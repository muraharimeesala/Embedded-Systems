#include<stdio.h>
struct Complex{
	float real;
	float img;
};
struct Complex addComplex(struct Complex n1,struct Complex n2){
	struct Complex result;
	result.real=n1.real+n2.real;
	result.img=n1.img+n2.img;
	return result;
}
int main(){
	struct Complex num1,num2,sum;
	printf("Enter real and imaginary part of first complex number:");
	scanf("%f %f",&num1.real,&num1.img);
	printf("Enter real and imaginary part of second complex number:");
	scanf("%f %f",&num2.real,&num2.img);
	sum=addComplex(num1,num2);
	printf("Sum=%.2f+%.2f\n",sum.real,sum.img);
}
