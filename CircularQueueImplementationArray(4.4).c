#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if ((rear + 1) % N == front) {
        printf("Queue is full. Cannot enqueue %d\n", x);
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
        printf("Enqueued %d\n", x);
    }
}

void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is: ");
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[i]);
    }
}

int main()
{
    // Test enqueue and display functions
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();

    enqueue(4);
    enqueue(5);
    enqueue(6); // This will result in "Queue is full" message
    display();

    return 0;
}