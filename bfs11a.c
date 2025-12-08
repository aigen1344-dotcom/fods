#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];     // adjacency matrix
int visited[MAX];      // visited array
int queue[MAX];
int front = -1, rear = -1;
int V;                 // number of vertices

// Insert element in queue
void enqueue(int x) {
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Remove element from queue
int dequeue() {
    if (front == -1)
        return -1;

    int val = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

// Create graph using adjacency matrix
void createGraph(int vertices) {
    V = vertices;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;

    printf("Edge created between %d and %d\n", u, v);
}

// BFS Function
void bfs(int start) {
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");

    visited[start] = 1;
    enqueue(start);

    while (front != -1) {
        int node = dequeue();
        printf("%d ", node);

        // visit all neighbors
        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    printf("\n");
}

// Display adjacency matrix
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {

    createGraph(5);

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(0, 4);

    displayMatrix();

    bfs(0);

    return 0;
}
