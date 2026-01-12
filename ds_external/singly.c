#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* Insert at front */
void insertFront(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Element inserted at front!\n");
}

/* Insert at end */
void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Element inserted at end!\n");
}

/* Insert at position (1-based index) */
void insertPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertFront(data);
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Element inserted at position %d!\n", position);
}

/* Delete front */
void deleteFront() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Front element deleted!\n");
}

/* Delete end */
void deleteEnd() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
    printf("End element deleted!\n");
}

/* Delete at position */
void deletePosition(int position) {
    if (head == NULL || position <= 0) {
        printf("Invalid operation\n");
        return;
    }

    if (position == 1) {
        deleteFront();
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Element deleted from position %d!\n", position);
}

/* Display list */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Main menu */
int main() {
    int choice, data, position;

    while (1) {
        printf("\n1.Insert Front\n2.Insert End\n3.Insert Position\n");
        printf("4.Delete Front\n5.Delete End\n6.Delete Position\n");
        printf("7.Display\n8.Exit\n");
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
            printf("Enter position: ");
            scanf("%d", &position);
            insertPosition(data, position);
            break;

        case 4:
            deleteFront();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            printf("Enter position: ");
            scanf("%d", &position);
            deletePosition(position);
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
