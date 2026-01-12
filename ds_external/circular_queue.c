#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* Enqueue */
void enqueue(int data) {

    // Check overflow
    if ((rear + 1) % MAX == front) {
        printf("Overflow (Queue Full)\n");
        return;
    }

    // First insertion
    if (front == -1) {
        front = rear = 0;
    } 
    else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
    printf("%d enqueued\n", data);
}

/* Dequeue */
void dequeue() {

    if (front == -1) {
        printf("Underflow (Queue Empty)\n");
        return;
    }

    printf("%d dequeued\n", queue[front]);

    // Only one element
    if (front == rear) {
        front = rear = -1;
    } 
    else {
        front = (front + 1) % MAX;
    }
}

/* Display */
void display() {

    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;

    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}
