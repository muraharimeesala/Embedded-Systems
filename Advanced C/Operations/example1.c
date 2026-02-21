#include <stdio.h>
int main(){
       	int flag=0x0f;
	flag &= ~0x02;
	printf("%d",flag);
	return 0;
}
