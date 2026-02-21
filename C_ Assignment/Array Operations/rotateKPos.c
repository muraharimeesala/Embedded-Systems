#include<stdio.h>
int main(){
        int n,i,j,k,arr[100];
        printf("Enter array size:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d", &arr[i]);
        }
	printf("Enter positions to rotate:");
	scanf("%d",&k);
        i=0;
        j=k-1;
        while(i<j){               // Left Rotation
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
        }
	/*i=k;
        j=n-1;
        while(i<j){             // Right Rotation
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
        }
	*/
	for(i=0;i<n;i++){
		printf("%d",arr[i]);

	}
}

