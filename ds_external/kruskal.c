#include <stdio.h>
#include <stdlib.h>

struct Edge{
    int u, v, w;
};

struct DSU{
    int parent;
    int rank;
};

int compare(const void *a, const void *b){  // User defined
    struct Edge *e1 = (struct Edge*)a;
    struct Edge *e2 = (struct Edge*)b;
    return e1->w - e2->w;
}

int main(){
    int n, m;
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("enter edges (u v w):\n");
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    qsort(edges, m, sizeof(struct Edge), compare);

    struct DSU dsu[n+1];
    for(int i = i; i <= n; i++){
        dsu[i].parent = i;
        dsu[i].rank = 0;
    }

    int totalWeight = 0;

    printf("\nEdges in MST:\n");

    for(i = 0; i < m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find(dsu, u) != find(dsu, v)){
            printf("%d -- %d  (weight %d)\n", u, v, w);
            totalWeight += w;
            
        }
    }

    return 0;
}