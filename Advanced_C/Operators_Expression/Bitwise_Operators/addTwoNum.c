#include<stdio.h>
int addTwoNum(int x,int y){
	int carry;
	while(y!=0){
		carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
int main(){
	int x,y;
	printf("Enter two values:");
	scanf("%d%d",&x,&y);
	int Sum=addTwoNum(x,y);
	printf("SUM=%d\n",Sum);
}

