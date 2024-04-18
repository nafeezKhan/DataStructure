#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Declare deletefrompos before main
void deletefrompos(struct node **head);

int main()
{
    struct node *head, *new_node, *temp;
    head = 0;
    int choice = 1;

    while (choice)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &new_node->data);
        new_node->next = 0;

        if (head == 0)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }

        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
    }

    printf("Linked list:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Call deletefrompos function
    deletefrompos(&head);

    // Print the linked list after deletion
    printf("\nLinked list after deletion from the specified position:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

// Implement the deletefrompos function
void deletefrompos(struct node **head)
{
    struct node *nextnode;
    int pos, i = 1;
    struct node *temp = *head;

    printf("\nEnter position:\n");
    scanf("%d", &pos);

    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position for deletion.\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
