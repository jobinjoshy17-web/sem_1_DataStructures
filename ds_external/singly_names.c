#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *next;
};

struct Node *head = NULL;

void insertFront(char name[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
    printf("Student inserted!\n");
}

void insertEnd(char name[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student inserted!\n");
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertFront("Rahul");
    insertEnd("Amit");
    insertFront("Sneha");
    insertEnd("Priya");

    display();
    return 0;
}
