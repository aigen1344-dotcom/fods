#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
    int q[SIZE];
    int currSize = 0;
    int start = -1, end = -1;

void push(int x){
    if(currSize == SIZE){
        printf("Cannot push");
        return;
    }
    if(currSize == 0){
        start = 0, end = 0;
    }
    else end = (end+1)%SIZE;
    q[end] = x;
    currSize++;
}
int pop(){
    if(currSize == 0) return 0;
    int el = q[start];
    if(currSize == 1){
        start = -1,end = -1;
    }
    else{
        start = (start+1)%SIZE;
    }
    currSize--;
    return el;
}
int top(){
    if(currSize == 0) return 0;
    return q[start];
}
int size(){
    return currSize;
}
void display(){
    if(currSize == 0){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    
    int i = start;
    for(int count = 0; count < currSize; count++){
        printf("%d ", q[i]);
        i = (i + 1) % SIZE;
    }
}

int main(){
    printf("Queue operations : \n");
    while(1){
    printf("\n1.Enqueue an element \n2.Dequeue an element \n3.Peek the front element \n4. Display all elements \n5.Exit ");
    printf("\nEnter your choice :");
    int choice;
    int data;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter element to add : ");
            scanf("%d", &data);
            push(data);
            display();
            break;
        
        case 2:
            pop();
            display();
            break;

        case 3:
            top();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid");
    }
}
    return 0;
}
