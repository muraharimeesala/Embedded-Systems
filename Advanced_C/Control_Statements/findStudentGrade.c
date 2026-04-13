#include <stdio.h>

int main(){
	int m1,m2,m3,m4,total,per;
	printf("Enter 4 subjects marks:\n");
	scanf("%d %d %d %d",&m1,&m2,&m3,&m4);
	total=m1+m2+m3+m4;
	per=total/4;
	if(per>=85){
		printf("Grade A\n");
	}
	else if(per>=75 && per<=84){
		printf("Grade B\n");
	}
	else if(per>=60 && per<=74){
		printf("Grade C\n");
	}
	else if(per>=40 && per<=59){
		printf("Grade D\n");
	}
	else{
		printf("Grade F\n");
	}
	return 0;
}
