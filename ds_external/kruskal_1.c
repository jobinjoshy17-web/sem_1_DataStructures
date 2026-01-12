#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct Edge {
    int u, v, w;
};

struct Edge edges[MAX];
int parent[MAX];
int n, e;

/* Function prototypes */
int find(int i);
void unionSet(int u, int v);
void sortEdges();
void kruskal();

/* Find */
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

/* Union */
void unionSet(int u, int v) {
    int a = find(u);
    int b = find(v);
    parent[a] = b;
}

/* Bubble sort edges */
void sortEdges() {
    struct Edge temp;
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

/* Kruskal */
void kruskal() {
    int cost = 0, count = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges();

    printf("\nEdges in MST:\n");

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            printf("%d - %d (weight=%d)\n",
                   u, v, edges[i].w);
            cost += edges[i].w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total cost = %d\n", cost);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d",
              &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal();
    return 0;
}
