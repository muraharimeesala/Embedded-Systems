#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student{
	int id;
	char name[100];
};
struct Student *createStudent(int id,char *name){
	struct Student *s=(struct Student*)malloc(sizeof(struct Student));
	if(s==NULL){
		printf("Failed to allocate memory.\n");
		exit(1);
	}
	s->id=id;
	strcpy(s->name,name);
	return s;
}
int main(){
	int n,i;
	printf("Enter no of students:");
	scanf("%d",&n);
	struct Student *students[n];
	int id;
	char name[100];
	for(i=0;i<n;i++){
	printf("Student %d:\n",i+1);
	printf("ID:");
	scanf("%d",&id);
	printf("Name:");
	scanf("%s",name);
	students[i]=createStudent(id,name);
        }  
	struct Student **ptr=students;
	printf("Student Deatils:\n");
	for(i=0;i<n;i++){
		printf("ID: %d, Name:%s\n",ptr[i]->id,ptr[i]->name);
	}
	for(i=0;i<n;i++){
		free(students[i]);
	}
}
