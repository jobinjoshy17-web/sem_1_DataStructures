#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(newNode == NULL){
        printf("Stack overflow\n");
        return;
    }

    newNode -> data = data;
    newNode -> next = top;
    top = newNode;

    printf("%d pushed onto the stack\n", data);
}

void pop(){
    if(top == NULL){
        printf("Stack underflow\n\n");
        return;
    }

    struct Node *temp = top;
    printf("%d popped out of the stack\n", top -> data);
    top = top -> next;
    free(temp);
}

void display(){
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    struct Node *temp = top;
    
    printf("Stack elements : ");
    while(top != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(90);
    pop();

    display();
    return 0;
}