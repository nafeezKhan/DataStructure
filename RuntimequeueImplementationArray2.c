#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Overflow (queue is full)\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int x, i;

    // Enqueue elements onto the queue
    for (i = 0; i < N; i++)
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
