#include <stdio.h>
#include <stdlib.h> // is included for dynamic memory allocation functions like 'malloc()'

struct node
{
    int data;
    struct node *next;
};

void main()
{
    struct node *head, *new_node, *temp; // Declares three pointers to ''struct node''
    head = 0;                            //'head' (to store the address of the first node)
    int count = 0, choice = 1;           //'new_node' (to create new nodes)
                                         //'temp' (to traverse the list)
    while (choice)
    { //// Dynamically allocate memory for a new node
        new_node = (struct node *)malloc(sizeof(struct node));
        //// Input data for the new node
        printf("Enter data:\n");
        scanf("%d", &new_node->data);
        //// Initialize next pointer of the new node to 0
        new_node->next = 0;
        // Check if the list is empty
        if (head == 0)
        {
            head = temp = new_node; // Set head and temp to the new node
        }
        else
        {
            temp->next = new_node; // Link the new node to the existing list
            temp = new_node;       // Move temp to the new node
        }
        // Asks the user if they want to continue adding nodes
        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
    }
    // Traverses the linked list starting from the head and prints the data of each node.
    printf("Linked list:\n");
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++; // Increments the count variable for each node to count the number of nodes in the list
    }

    printf("\nCount: %d\n", count);
    // getch();
}
