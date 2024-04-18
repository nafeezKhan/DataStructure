#include <stdio.h>
#define N 5

int top = -1;
int stack[N];

void pop()
 {
    int item;
    if (top == -1) 
    {
        printf("Underflow\n");
    }
     else 
    {
        item = stack[top];
        top--;
        printf("Popped item is %d\n", item);
    }
}

int main()
 {
    int i, item;

    // Pushing items onto the stack
    for (i = 0; i < N; i++) 
    {
        printf("Enter item to push onto the stack: ");
        scanf("%d", &item);
        if (top < N - 1) 
        {
            //stack[++top] = item; (we can also write this)
            top++;
            stack[top] = item;
            printf("Pushed %d\n", item);
        }
         else 
        {
            printf("Overflow: Stack is full\n");
            break;
        }
    }

    // Popping items from the stack
    for (i = 0; i < N; i++) 
    {
        pop();
    }

    return 0;
}
