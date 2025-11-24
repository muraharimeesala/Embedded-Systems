#include<stdio.h>
struct Student{
char name[50];
int roll_no;
char branch[50];
float per;
};
int main(){
struct Student s1;
printf("Enter a name: ");
scanf("%s",s1.name);
printf("Enter roll_no: ");
scanf("%d",&s1.roll_no);
printf("Enter branch: ");
scanf("%s",s1.branch);
printf("Enter percentage: ");
scanf("%f",&s1.per);
printf("\n Student Details\n");
printf("Name:%s\n Roll_no:%d\n Branch:%s\n Per:%f\n",s1.name,s1.roll_no,s1.branch,s1.per);
}
