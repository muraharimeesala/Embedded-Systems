#include<stdio.h>
int main(){
int a[5]={10,20,30,40,50};
int *ptr;
ptr=a;
for(int i=0;i<5;i++){
printf("Element-%d: Value=%d Address=%p\n",i,ptr[i],(void*)&ptr[i]);
}
}

