#include<stdio.h>
#include<string.h>
struct NoteBook{
    char title[100];
    char author[50];
    long int ISBN;
    int pages;
};
void Display(struct NoteBook *ptr){
    printf("Enter Title:");
    fgets(ptr->title,sizeof(ptr->title),stdin);
    ptr->title[strcspn(ptr->title,"\n")]='\0';
    printf("Enter Author Name:");
    fgets(ptr->author,sizeof(ptr->author),stdin);
    ptr->author[strcspn(ptr->author,"\n")]='\0';
    printf("Enter isbn Number:");
    scanf("%ld",&ptr->ISBN);
    printf("Enter number of Pages:");
    scanf("%d",&ptr->pages);
    printf("Book Details:\n");
    printf("TITLE: %s\nAUTHOR: %s\nISBN_NO: %ld\nPAGES: %d\n",ptr->title,ptr->author,ptr->ISBN,ptr->pages);
}
int main(){
    struct NoteBook s;
    struct NoteBook *ptr;
    ptr=&s;
    Display(ptr);
}
