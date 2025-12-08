#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}n;
n *head = NULL;
n *create(int data){
    n *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->next = NULL;
    return p;
}
void insertAtPos(int data,int pos){
    n *newNode = create(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    if(pos==1){
        n *temp = head;
        while(temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        return;
    }
    n *temp = head;
    int i =1;
    while(i<pos-1 && temp->next != head){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deletePos(int pos){
    if(pos==1){
        n *temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        if(head = head->next){
            free(head);
            head = NULL;
            return;
        }
        temp->next = head->next;
        head = head->next;
        free(temp);
        return;
    }
    n *temp = head;
    n *prev = NULL;
    int i=1;
    while(i<pos - 1 && temp->next != NULL){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    free(temp);
    return;
}
void searchAndDelete(int val){
    if(head == NULL) return;
    n *temp = head;
    n *prev = NULL;
    if(head->data == val){
        deletePos(1);
        return;
    }
    do{
        prev = temp;
        temp = temp->next;

        if(temp->data = val){
            prev->next = temp->next;
            free(temp);
            return;
        }
    }while(temp != head);
    printf("not found");
}
void reverse(){
    if(head == NULL||head->next == head) return;
    n *curr = head;
    n *start = head;
    n *prev = NULL;
    n *nextNode = NULL;
    do{
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }while(curr != start);

    head->next = prev;
    head = prev;
}
void display(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    n *temp = head;
    printf("Circular LL: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");

}
int main(){
    int choice, data, pos;
    while (1) {
        printf("\n1. Create\n2. Insert at any position\n3. Delete from any position\n4. Search and delete\n5. Reverse\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                create(data);
                display();
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPos(data, pos);
                display();
                break;
            case 3:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deletePos(pos);
                display();
                break;
            case 4:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                searchAndDelete(data);
                display();
                break;
            case 5:
                reverse();
                display();
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}