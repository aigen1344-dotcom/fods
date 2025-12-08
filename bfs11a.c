#include<stdio.h>
#include<stdlib.h>
struct node{
    int vertex;
    struct node *next;
};
struct node *arr[10];
int visited[10];
int queue[10];
int start = -1,end = -1;
void createVertex(int v){
    arr[v] = NULL;
    printf("\nVertex %d created",v);
}
void createEdge(int s,int d){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->vertex = d;
    p->next = arr[s];
    arr[s] = p;

    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->vertex = s;
    q->next = arr[d];
    arr[d] = q;
    printf("\nEdge create between %d and %d ",s,d);
}
void enqueue(int val){
    if(end == -1){
        start = 0,end = 0;
    }
    else{
        end++;
    }
    queue[end] = val;
}
int dequeue(){
    int el = queue[start];
    if(start == end){
        start = -1, end  = -1;
    }
    else{
        start++;
    }
    return el;
}

void bfs(int s){
    start = -1,end = -1;
    for(int i=0;i<11;i++) visited[i] = 0;
    visited[s] = 1;
    enqueue(s);
    printf("\nBFS traversal ");
    while(start != -1){
        int v = dequeue();
        printf("%d ",v);
        struct node *p = arr[v];
        while(p != NULL){
            if(!visited[p->vertex]){
                visited[p->vertex] = 1;
                enqueue(p->vertex);
            }
            p=p->next;
        }
    }
}
int main(){
    for(int i=1;i<5;i++){
        createVertex(i);
    }
    createEdge(1,2);
    createEdge(2,4);
    createEdge(3,2);
    createEdge(1,4);
    bfs(1);
    return 0;
}