#include <stdio.h>

#define MAX 100

int front = -1, rear = -1;
int queue[MAX];

void enqueue(int data){

    if(rear == MAX - 1){
        printf("Overflow\n");
        return;
    }
    
    if(front == -1){
        front = 0;
    }

    rear++;
    queue[rear] = data;
    printf("%d enqueued\n");
}

void dequeue(){
    
    if(front == -1 || front > rear){
        printf("Underflow\n");
    }
    
    printf("%d dequeued\n", queue[front]);
    front++;

    // Reset queue when last element is removed
    if (front > rear) {
        front = rear = -1;
    }
}

void display(){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}