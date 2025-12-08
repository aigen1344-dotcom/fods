#include<stdio.h>
#include<stdlib.h>
struct a{
    int aadhar;
    struct a *next;
};
struct a *head = NULL;
void insertHead(int val){
    struct a *p = (struct a *)malloc(sizeof(struct a));
    p->aadhar = val;
    p->next = NULL;
    p->next = head;
    head = p;
}
void insert(int val){
    struct a *p = (struct a *)malloc(sizeof(struct a));
    p->aadhar = val;
    p->next = NULL;
    if(head == NULL) head = p;
    else{
        struct a *q = head;
        while(q->next != NULL){
            q = q->next;
        }
        q->next = p;
    }
}
void insertAtPos(int val , int pos){
    struct a *p = (struct a *)malloc(sizeof(struct a));
    p->aadhar = val;
    p->next = NULL;
    
    struct a *temp = head;
    int cnt = 0;
    while(cnt < pos - 1){
        cnt++;
        // if(temp == head) printf("Invalid");
        // temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
}
void display(){
    struct a *q=head;
    while(q!=NULL){
        printf(" %d ",q->aadhar);
        q=q->next;
    }
    printf("\n");
}
int main(){
    insert(1);
    insert(2);
    insert(35);
    insert(34);
    insert(4);
    display();
    insertHead(10);
    display();
    insertHead(11);
    display();
    insertAtPos(32,2);
    display();
    insertAtPos(43,4);
    display();
    return 0;
}