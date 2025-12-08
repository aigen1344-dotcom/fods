#include<stdio.h>
#define SIZE 10
int hashTable[SIZE];

void initialize(){
    for(int i = 0;i<SIZE;i++){
        hashTable[i] = -1;
    }
}

void insert(int key){
    int index = key % SIZE;
    int orignalIndex = index;
    int i = 0;
    while(hashTable[index] != -1){
        printf("Collision at index %d ->",index);
        index = (orignalIndex + ++i) % SIZE;
        if(i==SIZE){
            printf("\nHash Table is full \n");
        } 
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n",key,index);
}

void search(int key){
    int index = key % SIZE;
    int originalIndex = index;
    int i = 0;
    while(hashTable[index] != -1){
        if(hashTable[index] == key){
            printf("\nElement %d found at index %d\n",key,index);
            return;
        }
        index = (originalIndex + ++i) % SIZE;
        if(i == SIZE) break;
    }
    printf("\nElement not found \n");
}

void delete(int key){
    int index = key % SIZE;
    int originalIndex = index;
    int i = 0;
    while(hashTable[index] != -1){
        if(hashTable[index] == key){
            hashTable[index] = -1;
            printf("\nElement %d deleted successfully\n",key);
            return;
        }
        index = (originalIndex + ++i) % SIZE;
        if(i == SIZE) break;
    }
    printf("\nElement %d not found\n",key);
}

void display(){
    printf("\n Hash Table ->");
    for(int i = 0;i<SIZE;i++){
        printf(" %d ",i);
    }
    printf("\n Values ->");
    for(int i = 0;i<SIZE;i++){
        printf(" %d ",hashTable[i]);
    }
}

int main(){
    initialize();

    insert(5);
    insert(15);
    insert(25);
    insert(35);

    search(25);
    delete(15);
    insert(45);

    display();
    return 0;
}