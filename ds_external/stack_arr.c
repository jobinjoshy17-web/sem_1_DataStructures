#include <stdio.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int value){
    if(top == MAX - 1){
        printf("Overflow\n");
    }
    else{
        top++;
        stack[top] = value;
        printf("%d value pushed!\n", value);
    }
}

int pop(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        int popped = stack[top];
        top--;
        return popped;
    }
}

int peek(){
    if(top == -1){
        printf("Underflow\n");
    }
    else{
        print("%d", &stack[top]);
    }
}

int main(){
    int value, choice;
    while(1){
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n");
    }

    return 0;
}