#include <stdio.h>

#define MAX_SIZE 7

int front = -1;
int rear = -1;

void enqueue(int queue[],int a)
{
    if(rear > MAX_SIZE - 1)
    {
        printf("\n Queue full!");
        return;
    }
    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
        queue[rear] = a;
        // printf("\n Value of front = %d ",front);
    }
    else
    {
        rear++;
        // printf("\n Value of rear = %d ",rear);
        queue[rear] = a;
    }
}

void dequeue(int queue[])
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty!!");
    }
    else if(front < MAX_SIZE -1)
    {
        queue[front] = 0;
        front++;
    }
}

void display(int queue[])
{
    for (int i = front; i <= rear; i++)
    {
        // printf("\n Value of i = %d ", i);
        printf("\t %d", queue[i]);
    }
    
}

int main()
{
    int q[MAX_SIZE];
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);
    display(q);
    dequeue(q);
    dequeue(q);
    printf("\n\n");
    display(q);
    return 0;
}