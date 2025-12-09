#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *next;
    struct Node *back;
    int data;
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
void deleteMiddle(){
    struct Node *slow = head;
    struct Node *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node *prev = slow->back;
    struct Node *front = slow->next;
    prev->next = front;
    front->back = prev;
    slow->next = slow->back = NULL;
    free(slow);
}
void delHead(){
    struct Node *temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = temp->back = NULL;
    free(temp);
}
void delTail(){
    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->back->next = NULL;
    temp->back = NULL;
    free(temp);
}
void display(){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    for(int i=1;i<=10;i++){
        insert(i);
    }
    display();
    deleteMiddle();
    display();
    delHead();
    display();
    delTail();
    display();
    return 0;
}