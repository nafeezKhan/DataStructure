#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *tail;//tail is used to traverse the linked list and print the data of each node.
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
int main()
{
    create();
    display();
    InsertAtBegining();
    printf("After Insert At Begining:\n");
    display();
    return 0;
}