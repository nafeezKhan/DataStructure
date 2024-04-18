#include <stdio.h>
#define N 5

int top = -1;
int stack[N];

void push()
{
    int x;
    printf("Enter data:\n");
    scanf("%d", &x);

    if (top == N - 1)
    {
        printf("Overflow condition\n");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int main()
{
    int i;
    for (i = 0; i < 5; i++)
    {
        push();
    }

    printf("Stack content:\n");
    for (i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}
