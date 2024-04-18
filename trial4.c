#include <stdio.h>
#include <stdlib.h>

#define N 50

int *queue;
int front = -1;
int rear = -1;

void enqueue(int x, int size)
{
    if (rear == size - 1)
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

int dequeue()
{
    int element;

    if (front == -1 && rear == -1)
    {
        printf("Underflow (queue is empty)\n");
        return -1; // Return a special value to indicate underflow
    }
    else if (front == rear)
    {
        element = queue[front];
        front = rear = -1;
    }
    else
    {
        element = queue[front];
        front++;
    }

    return element;
}

void BFS(int graph[][N], int start, int visited[], int size)
{
    enqueue(start, size);
    visited[start] = 1;

    while (front != -1)
    {
        int current = dequeue();
        printf("%d ", current);
        int i;
        for (i = 1; i <= size; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(i, size);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int size, i, j;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    queue = (int *)malloc(size * sizeof(int));

    int graph[N][N];
    int visited[N];

    // Input adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", size, size);
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 1; i <= size; i++)
    {
        visited[i] = 0;
    }

    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    BFS(graph, startNode, visited, size);

    free(queue); // Free dynamically allocated memory

    return 0;
}
