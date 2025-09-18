#include <stdio.h>

#define MAX_SIZE 7

int front = -1;
int rear = -1;

void enqueue(int queue[], int data)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Queue is full\n");
        return;
    }
    
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = data;
}

void dequeue(int queue[])
{
    int data;
    if (front == -1)
    {
        printf("Queue is empty");
        return;
    }
    
    data = queue[front];
    printf("Dequeued element: %d\n",data);
    queue[front] = 0;
    if (front == rear)
    {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
    }
    
    
}

void display(int queue[])
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;

    }
    
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
    
}

int main()
{

    int queue[MAX_SIZE] = {0};

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);
    enqueue(queue, 60);

    display(queue);

    dequeue(queue);
    dequeue(queue);

    display(queue);

    enqueue(queue, 70);
    enqueue(queue, 80);

    display(queue);


    return 0;
}