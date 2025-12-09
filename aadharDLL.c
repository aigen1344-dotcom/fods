#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *back;
};
struct Node *head = NULL;
void insert(int data){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    p->back = NULL;
    if(head == NULL){
        head = p;
        
        return;
    }
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = p;
    p->back = temp;
} 
void insertMiddle(int data,int pos){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    int cnt = 0;
    struct Node *temp = head;
    while(temp->next != NULL){
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    temp->back->next = p;
    p->back = temp->back;
    p->next = temp;
    temp->back = p;
}
void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }

}
int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insertMiddle(5,3);
    display();
    return 0;
}