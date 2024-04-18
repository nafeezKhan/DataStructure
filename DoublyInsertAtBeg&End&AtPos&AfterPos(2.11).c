#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail;
int count = 0; // declare count globally;for counting the nodes

void create()
{
    head = 0;
    int choice = 1;

    while (choice)
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data:\n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
        count++;
    }
}

void display()
{
    struct node *tail;
    tail = head;
    while (tail != 0)
    {
        printf("%d ", tail->data); // Add a space after %d; making the output more readable
        tail = tail->next;
    }
}
void InsertAtBegining()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at begining :\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void InsertAtPosition()
{
    int pos;
    int i = 1;
    printf("\nEnter position:\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }
    else if (pos==1)
    {
        InsertAtBegining();
    }
    else if (pos==count)
    {
        InsertAtEnd();
    }
    
    
    else
    {
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    while (i < pos - 1)//***
    {
        temp = temp->next;
        i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;//assigning the value of newnode to the prev pointer of the node that comes after newnode
    }
    
   
}

void InsertAfterPosition()
{
    int pos;
    int i = 1;
    printf("\nEnter position:\n");
    scanf("%d", &pos);

    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }
    else
    {
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    while (i < pos)//****
    {
        temp = temp->next;
        i++;
    }

    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->next->prev = newnode;
    }
    
   
}
void InsertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert at end :\n");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

int main()
{
    create();
    display();
    InsertAtPosition();
    printf("After Insert At Position:\n");
    display();
    return 0;
}
