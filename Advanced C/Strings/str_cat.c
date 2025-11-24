#include<stdio.h>
#include<string.h>
int main(){
char str[100],arr[100];
printf("Enter first string:");
//fgets(str,sizeof(str),stdin);
scanf("%s",arr);
printf("Enter second string:");
//fgets(arr,sizeof(arr),stdin);
strcat(str,arr);
printf("After Concatenated:%s",arr);
}

