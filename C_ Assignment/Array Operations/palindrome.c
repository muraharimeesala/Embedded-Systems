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
	j=n-1;
	while(i<j){
		if(arr[i]!=arr[j]){
			break;
		}
		i++;
		j--;
	}
	if(arr[i]==arr[j]){
		printf("Its a palindrome.\n");
	}
	else{
		printf("Its not a palidrome.\n");
	}
}

