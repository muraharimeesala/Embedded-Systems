#include<stdio.h>
struct student{
    char name[10];
    int roll;
    int marks;
};
void inc_marks(struct student *sptr){
    (sptr->marks)++;
}
void display(struct student *sptr){
    //for(int i=0;i<2;i++){
    printf("Name -%s\t",sptr->name);
    printf("Roll_no -%d\t",sptr->roll);
    printf("Marks -%d\n",sptr->marks);
}
int main(){
    int i;
    struct student s[2];
    for(i=0;i<2;i++){
        printf("Student details:",i);
        scanf("%d",&s[i]);
        printf("Enter name:");
        scanf("%s",s[i].name);
        printf("Enter roll_no:");
        scanf("%d",&s[i].roll);
        printf("Enter marks:");
        scanf("%d",&s[i].marks);
    }
    for(i=0;i<2;i++){
    inc_marks(&s[i]);
    inc_marks(&s[i]);
    printf("After incremting the student marks:\n");
    for(i=0;i<2;i++){
    display(&s[i]);
    display(&s[i]);
    }
}
}
