#include<stdio.h>
struct Student{
    char Name[100];
    int Roll;
    float Per;
};
void Input(struct Student s){
    printf("Enter name: ");
    scanf("%s",s.Name);
    printf("Enter roll no: ");
    scanf("%d",&s.Roll);
    printf("Enter percentage: ");
    scanf("%f",&s.Per);
    printf("Student Details:\n");
    printf("name: %s\nroll_no: %d\npercentage: %f\n",s.Name,s.Roll,s.Per);
}
int main(){
    struct Student s;
    Input(s);
}
