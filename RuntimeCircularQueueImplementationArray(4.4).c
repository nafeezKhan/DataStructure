#include <stdio.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) 
{
    if (front == -1 && rear == -1)
     {
        front = rear = 0;
        queue[rear] = x;
    } 
    else if ((rear + 1) % N == front)
     {
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
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[i]);
    }
}

int main()
 {
    int x;

    // Test enqueue and display functions
    for (;;)//infinity loop 
    {
        printf("Enter an element to enqueue (or -1 to stop): ");
        scanf("%d", &x);

        if (x == -1) {
            break;
        }

        enqueue(x);
         // Display the updated queue after each enqueue operation
        display();
    }
     // Display the updated queue after all dequeue operations
    //display();
    return 0;
}
