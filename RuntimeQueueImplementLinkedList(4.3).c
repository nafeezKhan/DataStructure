#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = 0;
struct node *rear = 0;

void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        while (temp != 0)
        {
            printf("%d ", temp->data); // Add a space for better readability
            temp = temp->next;
        }
        printf("\n"); // Add a newline for better formatting
    }
}

int main()
{
    int x, i;

    // Enqueue elements onto the queue
    for (i = 0; i < 5; i++)
    {
        printf("Enter element to enqueue: ");
        scanf("%d", &x);

        enqueue(x);

        // Display the updated queue after each enqueue operation
        display();
    }
     // Display all elements in the queue after all enqueue operations
    //display();

    return 0;
}
