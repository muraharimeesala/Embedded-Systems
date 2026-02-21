#include<stdio.h>
int mulTwoNum(int x,int y){
	int result;
	while(y>0){
		if(y&1){
			result=result+x;
		}
		x<<=1;
		y>>=1;
	}
	return result;
}
int main(){
	int x,y;
	printf("Enter two values:");
	scanf("%d%d",&x,&y);
	int Mul=mulTwoNum(x,y);
	printf("MUL=%d\n",Mul);
}

