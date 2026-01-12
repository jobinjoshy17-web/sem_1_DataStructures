#include <stdio.h>

#define MAX 15
#define INF 999999

void prims(int adj[MAX][MAX], int n){
    
    int visited[MAX] = {0};
    int no_of_edges = 0;

    visited[0] = 1;
    printf("Edges in the Minimum Spanning Tree:\n");
    while(no_of_edges < n-1){
        int x = -1, y = -1; //“No valid vertex has been selected yet.”
        int min = INF;

        for(int i = 0; i < n; i++){
            if(visited[i]){ // visited[0] = 1
                for(int j = 0; j < n; j++){
                    if(!visited[j] && adj[i][j] != 0 && adj[i][j] < min){
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d (weight = %d)", x, y, adj[x][y]);
        no_of_edges++;
        visited[y] = 1;
    }
}

int main(){
    
    int adj[MAX][MAX], n, i, j;
    printf("enter number of vertices : ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    prims(adj, n);

    return 0;
}