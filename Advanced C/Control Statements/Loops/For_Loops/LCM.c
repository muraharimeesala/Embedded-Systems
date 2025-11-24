#include<stdio.h>
int main(){
	int a,b,lcm;
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	for(lcm=(a>b?a:b); ;lcm++){
		if(lcm%a==0 && lcm%b==0){
			printf("LCM of %d and %d is: %d",a,b,lcm);
			break;
		}
	}
}
