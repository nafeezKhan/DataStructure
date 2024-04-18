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
    head = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert:\n");
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

    // The rest of your program...

    return 0;
}
