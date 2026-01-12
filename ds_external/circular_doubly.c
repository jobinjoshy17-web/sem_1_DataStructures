#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

/* Insert at front */
void insertFront(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Element inserted at front!\n");
}

/* Insert at end */
void insertEnd(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node *last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
    printf("Element inserted at end!\n");
}

/* Delete front */
void deleteFront() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        free(temp);
    }
    printf("Front element deleted!\n");
}

/* Delete end */
void deleteEnd() {
    if (head == NULL) {
        printf("Underflow\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head->prev;
        struct Node *secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        free(last);
    }
    printf("End element deleted!\n");
}

/* Display list */
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1.Insert Front\n2.Insert End\n3.Delete Front\n4.Delete End\n5.Display\n6.Exit\n");
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
            deleteFront();
            break;

        case 4:
            deleteEnd();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
