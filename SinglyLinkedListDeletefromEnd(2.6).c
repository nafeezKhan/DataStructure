#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Declare deletefromend before main
void deletefromend(struct node **head);

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

    // Call deletefromend function
    deletefromend(&head);

    // Print the linked list after deletion
    printf("\nLinked list after deletion from the end:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}

// Implement the deletefromend function
void deletefromend(struct node **head)
{
    struct node *temp, *prevnode;
    temp = *head;
    prevnode = NULL;

    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        *head = 0;
    }
    else
    {
        prevnode->next = 0;
    }

    free(temp);
}
