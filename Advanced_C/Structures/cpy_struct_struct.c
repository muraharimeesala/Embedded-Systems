#include<stdio.h>
#include<string.h>
struct Student{
    char name[10];
    int roll;
    float per;
}s1,s2;
int main(){

strcpy(s1.name,"Murahari");
s1.roll=1;
s1.per=83.23;
s2=s1;
printf(" Student Details:\n");
    printf(" Name: %s\n Roll_no: %d\n Per: %f\n",s2.name,s2.roll,s2.per);
}

