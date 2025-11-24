#include<stdio.h>
struct student{
    char name[10];
    int roll;
    int marks;
};
struct student *change(struct student *s){
    s->marks+=5;
    s->roll-=2;
    return s;
}
void display(struct student s){
    //for(int i=0;i<2;i++){
    printf("Name -%s\t",s.name);
    printf("Roll_no -%d\t",s.roll);
    printf("Marks -%d\n",s.marks);
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
       change(&s[i]);
    }
        printf("After changing details:\n");
        for(i=0;i<2;i++){
            display(s[i]);
    }
}
