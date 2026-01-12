#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

/* INSERT AT FRONT */
void insertFront(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    printf("Element inserted at front!\n");
}

/* INSERT AT END */
void insertEnd(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Element inserted at end!\n");
}

/* INSERT AT POSITION (0-based) */
void insertPosition(int position, int data) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        insertFront(data);
        return;
    }

    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    printf("Element inserted at position %d!\n", position);
}

/* DELETE FROM FRONT */
void deleteFront() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Front element deleted!\n");
}

/* DELETE FROM END */
void deleteEnd() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last element deleted!\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("Last element deleted!\n");
}

/* DELETE AT POSITION (0-based) */
void deletePosition(int position) {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (position == 0) {
        deleteFront();
        return;
    }

    struct Node *temp = head;
    for (int i = 0; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Element deleted from position %d!\n", position);
}

/* DISPLAY LIST */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* MAIN */
int main() {
    int choice = 0, data, position;

    while (choice != 8) {
        printf("\n---- DOUBLY LINKED LIST ----\n");
        printf("1. Insert Front\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Front\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("----------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertFront(data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position (0-based): ");
            scanf("%d", &position);
            insertPosition(position, data);
            break;

        case 4:
            deleteFront();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            printf("Enter position (0-based): ");
            scanf("%d", &position);
            deletePosition(position);
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
