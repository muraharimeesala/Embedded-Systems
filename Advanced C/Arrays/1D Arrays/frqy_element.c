#include<stdio.h>
int main(){
    int arr[100],n,visit[100],i,j;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
        visit[i]=0;
    }
    printf("Frequency of each element:\n");
    for(i=0;i<n;i++){
        if(visit[i]==1)
        continue;
        int count=1;
    for(j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
            count++;
            visit[j]=1;
        }
    }
    printf("%d occers %d times:\n",arr[i],count);
}
}
