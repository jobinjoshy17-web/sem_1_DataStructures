#include <stdio.h>

#define MAX 100

int top = -1;
int stack[MAX], visited[MAX], adj[MAX][MAX];

void push(int v){
    stack[++top] = v;
}

void DFS(int v, int n){
    visited[v] = 1;
    for(int i = 0; i < n; i++){
        if(adj[v][i] == 1 && !visited[i]){
            DFS(i, n);
        }
    }
    push(v);
}

int main(){
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    printf("--- Adjacency matrix ---\n\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i, n);
        }
    }

    printf("--- Topological sorting ---\n\n");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    
    return 0;
}

/* 

Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) 
such that for every directed edge from a vertex u to a vertex v (u → v), u appears before v 
in the ordering. Since the graph is acyclic, we can process vertices in a way that ensures 
dependencies are respected. The DFS-based approach works by exploring each vertex’s outgoing 
edges fully before marking it as finished. Once a vertex has no unvisited neighbors, we record it. 
This guarantees that all dependencies of a vertex are placed earlier in the order. At the end, 
reversing this finishing order yields a valid topological sorting.

takeUforward striver

*/