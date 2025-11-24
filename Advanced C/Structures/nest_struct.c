#include<stdio.h>
struct Address{
char City[100];
int Pin;
};
struct Student{
char Name[100];
int Roll_no;
char Branch[100];
struct Address s2;
};
int main(){
struct Student s1;
printf("Enter name: ");
scanf("%s",s1.Name);
printf("Enter roll number: ");
scanf("%d",&s1.Roll_no);
printf("Enter branch: ");
scanf("%s",s1.Branch);
printf("Enter city: ");
scanf("%s",s1.s2.City);
printf("Enter pin: ");
scanf("%d",&s1.s2.Pin);
printf("Student Details:\n"); 
printf(" NAME: %s\n ROLL_NO: %d\n BRANCH: %s\n ADDRESS: %s\n PIN: %d\n",s1.Name,s1.Roll_no,s1.Branch,s1.s2.City,s1.s2.Pin);
}


