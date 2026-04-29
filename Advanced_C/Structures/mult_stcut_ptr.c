#include<stdio.h>
struct Student{
char Name[50];
int Roll_no;
char Branch[50];
float Per;
};
int main(){
struct Student s1[3];
struct Student *ptr=s1;
int i;
for(i=0;i<3;i++){
printf("Details of Student[%d]:\n",i);
printf("Enter name: ");
scanf("%s",(ptr+i)->Name);
printf("Enter roll number: ");
scanf("%d",&(ptr+i)->Roll_no);
printf("Enter branch: ");
scanf("%s",(ptr+i)->Branch);
printf("Enter percentage: ");
scanf("%f",&(ptr+i)->Per);
}
for(i=0;i<3;i++){
printf("Std[%d]: Std_name:%s Std_roll: %d Std_branch: %s Std_per: %f\n",i,(ptr+i)->Name,(ptr+i)->Roll_no,(ptr+i)->Branch,(ptr+i)->Per);
}
}

