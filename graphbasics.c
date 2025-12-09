#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node *next;
};

struct node *arr[10]; // assume max 10 vertices
int count = 0;

void createVertex(int v) {
    arr[v] = NULL;
    count++;
    printf("\nVertex %d created successfully", v);
}

void createEdges(int s, int d) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->vertex = d;
    p->next = arr[s];
    arr[s] = p;

    // For undirected graph (add reverse edge)
    struct node *q = (struct node *)malloc(sizeof(struct node));
    q->vertex = s;
    q->next = arr[d];
    arr[d] = q;

    printf("\nEdge created between %d and %d", s, d);
}

void deleteVertex(int v) {
    struct node *p = arr[v];
    struct node *t;

    // Remove all edges from other vertices pointing to v
    while (p != NULL) {
        int vertex = p->vertex;
        struct node *q = arr[vertex];
        struct node *prev = NULL;

        while (q != NULL) {
            if (q->vertex == v) {
                if (prev == NULL) {
                    arr[vertex] = q->next;
                } else {
                    prev->next = q->next;
                }
                free(q);
                break; // vertex found and deleted, move on
            }
            prev = q;
            q = q->next;
        }

        t = p;
        p = p->next;
        free(t);
    }

    arr[v] = NULL;
    printf("\nVertex %d deleted successfully", v);
}

void display() {
    struct node *p;
    printf("\n\n--- Graph Adjacency List ---\n");
    for (int i = 1; i <= count; i++) {
        if (arr[i] != NULL) {
            printf("%d -> ", i);
            p = arr[i];
            while (p != NULL) {
                printf("%d -> ", p->vertex);
                p = p->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    int ch, v, s, d;
    do {
        printf("\n\n1. Create Vertices");
        printf("\n2. Create Edges");
        printf("\n3. Delete Vertex");
        printf("\n4. Display Graph");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                for (int i = 1; i <= 4; i++) {
                    createVertex(i);
                }
                break;

            case 2:
                createEdges(1, 2);
                createEdges(1, 3);
                createEdges(2, 3);
                createEdges(2, 4);
                createEdges(3, 4);
                display();
                break;

            case 3:
                printf("\nEnter vertex number to delete: ");
                scanf("%d", &v);
                deleteVertex(v);
                display();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nUnrecognized command");
        }
    } while (ch != 5);

    return 0;
}