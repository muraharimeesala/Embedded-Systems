#include<stdio.h>
struct Student{
char Name[50];
int Roll_no;
char Branch[50];
float Per;
};
int main(){
struct Student s1[3];
int i;
for(i=0;i<3;i++){
printf("Details of Student[%d]:\n",i);
printf("Enter name: ");
scanf("%s",s1[i].Name);
printf("Enter roll number: ");
scanf("%d",&s1[i].Roll_no);
printf("Enter branch: ");
scanf("%s",s1[i].Branch);
printf("Enter percentage: ");
scanf("%f",&s1[i].Per);
}
for(i=0;i<3;i++){
printf("Std[%d]: Std_name:%s Std_roll: %d Std_branch: %s Std_per: %f\n",i,s1[i].Name,s1[i].Roll_no,s1[i].Branch,s1[i].Per);
}
}

