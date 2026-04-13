#include<stdio.h>
int main(){
	unsigned int num;
	int i,pos;
	printf("Enter number:");
	scanf("%u",&num);
	printf("Enter bit position(0 to 31):");
	scanf("%d",&pos);
	printf("Before CLEAR:%d\n",num);
	for(i=31;i>=0;i--){
		printf("%d",(num>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
	num=num&~(1U<<pos);
   	printf("After CLEAR:%d\n",num);
        for(i=31;i>=0;i--){
                printf("%d",(num>>i)&1);
                if(i%4==0){
                        printf(" ");
                }
        }
	printf("\n");

}
