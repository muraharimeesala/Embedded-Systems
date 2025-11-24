#include<stdio.h>
#include<string.h>
struct Student{
    char name[10];
    int roll;
    float per;
}s;
int main(){
    struct Student;
    strcpy(s.name,"Murahari");
    s.roll=1;
    s.per=89.23;
    printf(" Student Details:\n");
    printf(" Name: %s\n Roll_no: %d\n Per: %f\n",s.name,s.roll,s.per);
}

