#include<stdio.h>
struct LeapYear{
    int day;
    int month;
    int year;
};
int Display(int year){
    if((year%4==0 && year%100!=0) || (year%400==0)){
        return 1;
    }
        else{
        return 0;
        }
}
int main(){
    struct LeapYear d;
    printf("Enter Date(DD-MM-YYYY):");
    scanf("%d %d %d",&d.day,&d.month,&d.year);
    printf("Entered date:%02d-%02d-%02d\n",d.day,d.month,d.year);
    if(Display(d.year)){
        printf("%d is a leap year.",d.year);
    }
    else
    printf("%d is not leap year.",d.year);
}

