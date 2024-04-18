#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// Function to print the linked list
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head, *new_node, *temp;
    head = 0;
    int count = 0, choice = 1;

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

    // Traverse and print the linked list
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("\nCount: %d\n", count);

    // Insert a new node at the end
    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Enter data you want to insert at the end:\n");
    scanf("%d", &(new_node->data));
    new_node->next = NULL;

    temp = head;

    if (temp == NULL)
    {
        head = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Print the full updated linked list after insertion at the end
    printf("Linked list after insertion at end:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
