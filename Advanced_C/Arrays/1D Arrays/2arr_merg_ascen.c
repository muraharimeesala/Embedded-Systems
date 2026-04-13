#include<stdio.h>
int main(){
        int n,m,i,j,k,a[100],b[100],c[100];
        printf("Enter size first array:");
        scanf("%d",&n);
        printf("Enter %d elements first array:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&a[i]);
        }
        printf("Enter size second array:");
        scanf("%d",&m);
        printf("Enter %d elements first array:\n",m);
        for(i=0;i<m;i++){
                scanf("%d",&b[i]);
        }
        i=0;
        j=0;
        k=0;
        while(i<n && j<m){
                if(a[i]<b[j]){
                        c[k++]=a[i++];
                }
                else{
                        c[k++]=b[j++];
                }
        }
        while(i<n){
                c[k++]=a[i++];
        }
        while(j<m){
                c[k++]=b[j++];
        }
        printf("Merged Array:\n");
        for(i=0;i<k;i++){
                printf("%d ",c[i]);
        }
}

