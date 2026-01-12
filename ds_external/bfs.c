#include <stdio.h>

#define MAX 100

int queue[MAX];
int rear = -1, front = -1;

void enqueue(int v){
    if(rear == MAX - 1){
        printf("Overflow!\n");
        return;
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = v;
    }
}

int dequeue(){
    int v;
    if(front == -1 || front > rear){
        printf("Underflow!\n");
        return -1;  // empty queue
    }
    v = queue[front];
    front++;
    return v;
}

void BFS(int adj[MAX][MAX], int n, int start){
    int visited[MAX] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal : ");
    while(front != -1 && front <= rear){    // while (queue is not empty)
        int node = dequeue();
        printf("%d", node);

        for(int i = 0; i < n; i++){
            if(adj[node][i] == 1 && !visited[i]){
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main(){
    int n, start, adj[MAX][MAX];
    printf("n = "); // number of vertices
    scanf("%d", &n);
    
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);    // 0 and 1
        }
    }

    printf("starting node : ");
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}