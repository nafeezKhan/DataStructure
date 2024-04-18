#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *newnode, *temp; //variable temp is used as a temporary pointer to traverse the linked list
void create()
{
    head = 0;
    int choice = 1;//variable choice is used to determine whether the user wants to continue adding nodes to the linked list.
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data:\n");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
    }
}
void display()
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);// Add a space after %d; making the output more readable
        temp = temp->next;
    }
}
int main()
{
    create();
    display();
    return 0;
}