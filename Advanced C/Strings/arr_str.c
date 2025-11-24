#include<stdio.h>
int main(){
    int n,i;
    printf("Enter no of strings:");
    scanf("%d",&n);
    char arr[n][100];
    getchar();
    for(i=0;i<n;i++){
        printf("String-%d: ",i);
        scanf("%s",&arr[i]);
    }
    printf("Entered Strings:\n");
    for(i=0;i<n;i++){
        printf("%s\n",arr[i]);
    }
}
