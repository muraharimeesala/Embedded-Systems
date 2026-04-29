#include<stdio.h>
int main(){
	int arr[10][10],arr1[10][10],i,j;
	int rows,cols,flag=1;
	printf("Enter no of rows:");
	scanf("%d",&rows);
	printf("Enter no of cols:");
	scanf("%d",&cols);
	printf("First matrix elements:\n");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("Second array elements:\n");
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			scanf("%d",&arr1[i][j]);
		}
	}
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++){
			if(arr[i][j]!=arr1[i][j]){
				flag=0;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}
	if(flag==1){
		printf("Both are  equal.\n");
	}
	else{
		printf("Both are not equal.\n");
	}
}


	
