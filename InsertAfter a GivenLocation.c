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
    int count = 3;//length of the linked list(here i assume 3)
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
    }

    return 0; // Corrected the return statement
}
