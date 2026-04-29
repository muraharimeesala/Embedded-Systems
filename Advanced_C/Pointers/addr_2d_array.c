#include<stdio.h>
int main(){
	int rows,cols,i,j;
	printf("Enter no of rows:");
	scanf("%d",&rows);
	printf("Enter no of cols:");
	scanf("%d",&cols);
	int arr[rows][cols];
	int *ptr=&arr[0][0];
	printf("Enter %d x %d matrix:\n",rows,cols);
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&arr[i][j]);
		}

	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			printf("Element[%d][%d] Value:%d Address:%p\n",i,j,*(ptr+i*cols+j),(ptr+i*cols+j));
		}
	}
}
