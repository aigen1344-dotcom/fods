#include <stdio.h>
#include<stdlib.h>
typedef struct a{
    int height;
    struct a *next;
} n;
n *head = NULL;
void insertHead(int val){
    struct a *p = (struct a *)malloc(sizeof(struct a));
    p->height = val;
    p->next = NULL;
    p->next = head;
    head = p;
}
void insert(int val){
    struct a *p = (struct a *)malloc(sizeof(struct a));
    p->height = val;
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
    p->height = val;
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
        printf(" %d ",q->height);
        q=q->next;
    }
    printf("\n");
}
void deleteMid(){
    n *fast = head;
    n *slow = head;
    n *prev = NULL;
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    free(slow);
    printf("Middle node deleted\n");
}
void deleteStart(){
    n *temp = head;
    head = head->next;
    free(temp);
    printf("first node deleted\n");
}
void deleteEnd(){
    n *temp = head;
    n *prev = NULL;
    while(temp->next != NULL){
        prev = temp;
        temp=temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("last node delete\n");
}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    insert(7);
    insert(8);
    insert(9);
    insert(10);
    display();
    deleteMid();
    display();
    deleteStart();
    display();
    deleteEnd();
    display();
    return 0;
}