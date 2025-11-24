#include<stdio.h>
int main(){
	int rows,cols,arr[rows][cols],oneD[rows*cols];
	int i,n,j,k=0;
	printf("Enter no of rows:");
	scanf("%d",&rows);
	printf("Enter no of cols:");
	scanf("%d",&cols);
	printf("Enter %dx%d matrix:\n",rows,cols);
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			oneD[k++]=arr[i][j];
		}
	}
	printf("1d array(row wise):\n");
	for(i=0;i<rows*cols;i++){
		printf("%d",oneD[i]);
	}
}
