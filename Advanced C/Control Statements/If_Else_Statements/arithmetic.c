#include<stdio.h>
int main(){
int a,b,choice;
printf("Enter A and B values:");
scanf("%d%d",&a,&b);
printf("Operation:\n1. sum\n2. sub\n3. mul\n4. div\n5. rem\n");
scanf("%d",&choice);
if(choice==1)
printf("Result=%d",a+b);
else if(choice==2)
printf("Result=%d",a-b);
else if(choice==3)
printf("Result=%d",a*b);
else if(choice==4)
printf("Result=%d",a/b);
else if(choice==5)
printf("Result=%d",a%b);
else
printf("Invalid choice");
}

  
