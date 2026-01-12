#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int data){
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    
    if(front == NULL){
        printf("Underflow\n");
        return;
    }

    struct Node *temp = front;
    printf("%d element dequeued\n", temp -> data);
    front = temp -> next;
    free(temp);
}

void display(){
    
    struct Node *temp = front;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
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