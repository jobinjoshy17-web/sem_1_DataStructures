#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void insertAtBeginning(struct node* list)
{
    if (head == NULL)
    {
        head = list;
    }
    else
    {
        head->prev = list;
        list->next = head;
        head = list;
    }
}

void insertAtPosition(struct node* list, int pos)
{
    int i = 1;
    struct node* temp = head;
    struct node* ptr = head;
    while (i <= pos)
    {
        ptr = temp;
        temp = temp->next;
        i++;
    }
    ptr->next = list;
    list->prev = ptr;
    list->next = temp;
    temp->prev = list;
}

void insertAtEnd(struct node* list)
{
    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list;
    list->prev = temp;
    list->next = NULL;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("\n Linked list is empty");
    }
    else
    {
        struct node* temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp); 
    }
}

void deleteAtPos(int pos)
{
    int i = 1;
    struct node* temp = head;
    struct node* ptr = head;
    while (i <= pos)
    {
        ptr = temp;
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    // setting the prev link for the node after the temp node
    temp->next->prev = ptr;
    return;
}

void deleteAtEnd()
{
    struct node* temp = head;
    struct node* ptr = head;
    while (temp->next != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = NULL;
    temp->prev = NULL;
    free(temp);
}

void display()
{
    struct node* temp = head;
    
    while (temp != NULL)
    {
        printf("%d \n",temp->data);
        temp = temp->next;
    }
    
}

void main()
{
   int choice = 0;
    while (choice < 8)
    {
        printf("\n1  Insert at beginning : ");
        printf("\n2  Insert at end : ");
        printf("\n3 Insert at a position : ");
        printf("\n4 delete at beginning : ");
        printf("\n5 delete at end : ");
        printf("\n6 delete at a position : ");
        printf("\n7 Display\t:");
        scanf("%d", &choice);
        int data,pos;
        switch (choice)
        {
        case 1:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            struct node* newNode = createNode(data);
            insertAtBeginning(newNode);
            break;
        case 2:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            {

                struct node* newNode = createNode(data);
                insertAtEnd(newNode);
            }
            break;
        case 3:
            printf("\n Enter the data to insert to the element : ");
            scanf("%d",&data);
            printf("\n Enter the position to insert the element to : ");
            scanf("%d",&pos);
            {

                struct node* newNode = createNode(data);
                insertAtPosition(newNode,pos);
            }
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("\n Enter the position to delete the element from : ");
            scanf("%d",&pos);
            deleteAtPos(pos);
            break;
        case 7:
            display();
            break;
        default:
            break;
        }

    }
    return;
}