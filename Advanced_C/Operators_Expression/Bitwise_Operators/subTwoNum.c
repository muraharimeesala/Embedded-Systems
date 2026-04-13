#include<stdio.h>
int subTwoNum(int x,int y){
       int result;
       result=x+(~y+1);
       	return result;
}
int main(){
        int x,y;
        printf("Enter two values:");
        scanf("%d%d",&x,&y);
        int Sub=subTwoNum(x,y);
        printf("SUB=%d\n",Sub);
}

