#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct s{
    struct s *next;
    int roll;
    int age;
    char name[30];
    struct s *prev;
};
struct s *head = NULL;

void insert(int roll ,char n[], int age){
    struct s *p = (struct s *)malloc(sizeof(struct s));
    p->roll = roll;
    p->age = age;
    strcpy(p->name,n);
    p->next = NULL;
    if(head == NULL) head = p;
    else{
        struct s *q = head;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}
void display(){
    printf("Student Details \n");
    struct s *q = head;
    while(q != NULL){
        printf(" Name = %s , Roll = %d , Age = %d \n",q->name,q->roll,q->age);
        q=q->next;
    }    
}
int main(){
    insert(1,"khhsh",18);
    insert(2,"khush",19);
    insert(3,"khssh",17);
    display();
}