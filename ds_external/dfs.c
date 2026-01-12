// Depth-First Search

#include <stdio.h>

#define MAX 100

void DFS(int adj[MAX][MAX], int n, int v, int visited[]){
    visited[v] = 1;
    printf("%d", v);

    for(int i = 0; i < n; i++){
        if(adj[v][i] == 1 && !visited[i]){
            DFS(adj, n, i, visited);
        }
    }
}

int main(){
    int n, start, adj[MAX][MAX];
    printf("enter number of vertices: ");
    scanf("%d", &n);

    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    printf("enter starting vertex : ");
    scanf("%d", &start);

    int visited[MAX] = {0};
    DFS(adj, n, start, visited);

    return 0;
}