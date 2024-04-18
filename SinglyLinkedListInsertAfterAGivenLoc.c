#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *newnode, *temp;
    head = 0;
    int count = 0, choice = 1;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0, 1)?\n");
        scanf("%d", &choice);
    }

    printf("Linked list:\n");
    temp = head;
    count = 0;

    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("\nCount: %d\n");

    // Now, let's insert after a given position

    int pos, i = 1;
    printf("Enter the position to insert after:\n");
    scanf("%d", &pos);

    if (pos > count || pos < 1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        // Now temp points to the node after which we want to insert

        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:\n");
        scanf("%d", &newnode->data);

        newnode->next = temp->next;
        temp->next = newnode;

        // Traverse and print the entire updated list

        printf("Updated Linked list:\n");
        temp = head;
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }

    return 0;
}
