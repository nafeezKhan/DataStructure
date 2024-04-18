#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

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

    // Insert a new node at the beginning
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == 0)
    {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Enter data you want to insert:\n");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    // Print the updated linked list
    printf("Linked list after insertion at begining:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
