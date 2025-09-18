// SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // data and link part of a node
};
struct Node *head = NULL;

void insertFront(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("Element Inserted!\n");
}

void insertEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        struct Node* temp = head;
        while(temp -> next != NULL){    // Not (temp != NULL)
            temp = temp -> next;
        }
        temp -> next = newNode;     // Setting the last node as newNode
        newNode -> next = NULL;
    }
    printf("Element Inserted!\n");
}

void insertPosition(int position, int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> data = data;
    struct Node* temp = head;
    if(position < 0){
        printf("Invalid position");
        return;
    }

    if (position = 0 || head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        for(int i = 1; i < position && temp -> next != NULL; i++){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    printf("Element Inserted!\n");
}

void display()
{
    if (head == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("<-%d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deleteFront(){     // Did not write the case when there is only 1 elem
    struct Node* temp = head;
    if(head == NULL){
        printf("Underflow\n");
    }
    else{
        head = head -> next;
        temp -> next = NULL;
        free(temp);
    }
    printf("Element deleted!\n");
}

void deleteEnd(){
    struct Node* temp = head;
    if(head == NULL){
        printf("Underflow\n");
    }
    else{
        while (temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
    }
    printf("Element deleted!\n");
}

void deletePosition(int position){
    struct Node* temp = head;
    if(head == NULL){
        printf("Underflow\n");
    }

    if (position == 1){     //IMPORTANT
        head = temp -> next;
        free(temp);
    }
    
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp -> next;
    }
    // temp -> next = temp -> next -> next;
    if(temp -> next == NULL || temp == NULL){
        printf("Position out of bounds\n");
    }

    struct Node* deletedNode = temp -> next;
    temp -> next = temp -> next -> next;
    free(deletedNode);
}

int main()
{
    int choice, data, position;
    printf("\n##################\n");
    printf("1. InsertFront\n2. InsertEnd\n3. InsertPosition\n4. DeleteFront\n5. DeleteEnd\n6. DeletePosition\n7. Display\n8. EXIT\n");
    printf("##################\n");
    while (choice != 8)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertFront(data);
            break;
        
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertEnd(data);
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &data);
            printf("Enter the position: ");
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
            printf("Enter position: ");
            scanf("%d", &position);
            deletePosition(position);
            break;

        case 7: 
            display();
            break;

        case 8:
            printf("Exiting...\n\n");
            exit(0);    // 0 denotes success
        }
    }
    return 0;
}