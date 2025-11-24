#include<stdio.h>
#include<string.h>
int main(){
char str1[100]="Murahari";
char str2[100]="Meesala";
char temp[100];
printf("Before Swapping\n");
printf("First String:%s\n",str1);
printf("Second Sting:%s\n",str2);
strcpy(temp,str1);
strcpy(str1,str2);
strcpy(str2,temp);
printf("After Swapping\n");
printf("First String:%s\n",str1);
printf("Second Sting:%s\n",str2);
}
