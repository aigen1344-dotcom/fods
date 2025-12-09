#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex;
    struct node *next;
};
#define SIZE 10
struct node *arr[SIZE];
int visited[SIZE] = {0};
int stack[SIZE];
int top = -1;
void createVertex(int v){
    arr[v] = NULL;
    printf("\nVertex %d created",v);
}
void createEdges(int s,int d){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->vertex = d;
    p->next = arr[s];
    arr[s] = p;

    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->vertex = s;
    q->next = arr[d];
    arr[d] = q;
    printf("\nEdge created between %d and %d",s,d);
}
void push(int x){
    stack[++top] = x;
}
int pop(){
    return stack[top--];
}
int isEmpty(){
    return top == -1;
}
void dfs(int start){
    printf("\nDFS traversal");
    push(start);
    visited[start] = 1;
    while(!isEmpty()){
        int v = pop();
        printf("%d ",v);
        struct node *p = arr[v];
        while(p != NULL){
            if(!visited[p->vertex]){
                visited[p->vertex] = 1;
                push(p->vertex);
            }
            p = p->next;
        }
    }
}
int main(){
    for (int i = 0; i < 5; i++) {
        createVertex(i);
    }

    // Create edges
    createEdges(0, 3);
    createEdges(0, 2);
    createEdges(0, 1);
    createEdges(1, 2);
    createEdges(2, 4);

    dfs(0);
    return 0;
}