#include<stdio.h>
int main(){
	int num,i=0,sum=0;
	printf("Enter elements of array:");
	scanf("%d",&num);
	int arr[num];
	while(i<num){
		printf("Element-%d:",i);
		scanf("%d",&arr[i]);
		i++;
	}
	i=0;
        printf("The sum of array:");
	while(i<num){
		sum=sum+arr[i];
		i++;
	}
		printf("%d\n",sum);
}

