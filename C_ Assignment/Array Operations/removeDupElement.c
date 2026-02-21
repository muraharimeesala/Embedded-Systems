#include<stdio.h>
int main(){
        int n,i,j,arr[100];
        printf("Enter array size:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d", &arr[i]);
        }
	i=0;
	for(j=i+1;j<n;j++){
		if(arr[i]!=arr[j]){
			i++;
			arr[i]=arr[j];
		}
	}
	int size=i+1;
	printf("After removing the dupliactes:\n");
	for(i=0;i<size;i++){
		printf("%d",arr[i]);
	}
}
