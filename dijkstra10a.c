#include<stdio.h>

#define V 6
#define INF 9999

int dist[V];
int C[V][V];
int parent[V];
int visited[V];

void initMatrix(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j) C[i][j] = 0;
            else C[i][j] = INF;
        }
    }
}

void costMatrix(int s,int d,int w){
    C[s][d] = w;
    C[d][s] = w; 
}

int minIdx(){
    int min = INF;
    int min_idx = -1;
    for(int v=0;v<V;v++){
        while(!visited[v] && dist[v] < min){
            min = dist[v];
            min_idx = v;
        }
    }
    return min_idx;
}
void dijkstra(int s){
    for(int i=0;i<V;i++){
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[s] = 0;
    for(int count = 0;count<V-1;count++){   
        int u = minIdx();
        if(u == -1) break;
        visited[u] = 1;

        for(int v=0;v<V;v++){
            if(!visited[v] && C[u][v] != INF && dist[u] + C[u][v] < dist[v]){
                dist[v] = dist[u] + C[u][v];
                parent[v] = u;
            }
        }
    }
}
void display(){
    printf("\nVertex\tDistance  Parent");
    for(int i=0;i<V;i++){
        printf("\n%d\t%d\t  %d",i,dist[i],parent[i]);
    }
}
int main(){
    initMatrix();
    costMatrix(0, 1, 1);
    costMatrix(0, 2, 4);
    costMatrix(1, 2, 2);
    costMatrix(2, 3, 3);
    costMatrix(2, 4, 1);
    costMatrix(2, 5, 6);
    costMatrix(3, 5, 2);
    costMatrix(4, 5, 3);
    dijkstra(5);
    display();
    return 0;
}