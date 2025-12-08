#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// ---------------------------
// INSERT AT HEAD
// ---------------------------
struct Node* insertHead(struct Node *head, int val) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = head;
    return temp;    // New head
}

// ---------------------------
// INSERT AT TAIL
// ---------------------------
struct Node* insertTail(struct Node *head, int val) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;

    if (head == NULL)  // empty list
        return temp;

    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = temp;
    return head;
}

// ---------------------------
// INSERT AT POSITION
// ---------------------------
struct Node* insertPosition(struct Node *head, int val, int pos) {
    if (pos == 1)
        return insertHead(head, val);

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// ---------------------------
// DELETE HEAD
// ---------------------------
struct Node* deleteHead(struct Node *head) {
    if (head == NULL) return NULL;

    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// ---------------------------
// DELETE TAIL
// ---------------------------
struct Node* deleteTail(struct Node *head) {
    if (head == NULL || head->next == NULL)
        return deleteHead(head);

    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next); // delete last node
    temp->next = NULL;

    return head;
}

// ---------------------------
// DELETE AT POSITION
// ---------------------------
struct Node* deletePos(struct Node *head, int pos) {
    if (pos == 1)
        return deleteHead(head);

    struct Node *temp = head;
    int count = 1;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return head;
    }

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    return head;
}

// ---------------------------
// DELETE BY VALUE
// ---------------------------
struct Node* deleteVal(struct Node *head, int val) {
    if (head == NULL) return NULL;

    if (head->data == val)
        return deleteHead(head);

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

// ---------------------------
// DISPLAY LIST
// ---------------------------
void display(struct Node *head) {
    struct Node *temp = head;

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------------------
// MAIN
// ---------------------------
int main() {
    struct Node *head = NULL;

    head = insertHead(head, 10);
    head = insertTail(head, 20);
    head = insertTail(head, 30);
    head = insertPosition(head, 15, 2);

    display(head);

    head = deleteHead(head);
    display(head);

    head = deleteTail(head);
    display(head);

    head = deleteVal(head, 20);
    display(head);

    return 0;
}
