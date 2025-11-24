#include<stdio.h>
struct Student{
char name[50];
int roll_no;
char branch[50];
float per;
};
void Input(struct Student *ptr){
printf("Enter a name: ");
scanf("%s",ptr->name);
printf("Enter roll_no: ");
scanf("%d",&ptr->roll_no);
printf("Enter branch: ");
scanf("%s",ptr->branch);
printf("Enter percentage: ");
scanf("%f",&ptr->per);
}
void Display(struct Student *ptr){
printf("\n Student Details\n");
printf(" Name:%s\n Roll_no:%d\n Branch:%s\n Per:%f\n",ptr->name,ptr->roll_no,ptr->branch,ptr->per);
}
int main(){
struct Student s1;
Input(&s1);
Display(&s1);
} s
