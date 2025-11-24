#include<stdio.h>
int main(){
	int x,n,choice;
	printf("Enter value:");
	scanf("%d",&x);
	printf("Enter bit position:");
	scanf("%d",&n);
	printf("1.Set\n2.Clear\n3.Toggle:\n");
	printf("Enter choice:");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			x=x|(1<<n);
			printf("After setting bit %d:%d\n",n,x);
			break;
		case 2:
			x=x&~(1<<n);
			printf("After clearing bit %d:%d\n",n,x);
			break;
	        case 3:
			x=x^(1<<n);
			printf("After toggling bit %d:%d\n",n,x);
			break;
		default:
			printf("Invalid choice.\n");
	}
}
