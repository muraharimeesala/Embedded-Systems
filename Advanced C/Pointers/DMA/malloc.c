#include<stdio.h>
#include<stdlib.h>
int main(){
int n,i;
int *p;
printf("Enter size of array:");
scanf("%d",&n);
p=(int*)malloc(sizeof(int)*n);
if(p==NULL){
printf("Memory allocation failed\n");
}
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&p[i]);
}
printf("Enter elements are:");
for(i=0;i<n;i++){
printf("%d \n",p[i]);
}
free(p);
}
