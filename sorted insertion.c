#include <stdio.h>

int main()
{
    int a[50], size, i, num, pos;

    printf("Enter size of array:\n");
    scanf("%d", &size);

    printf("Enter elements of array (sorted):\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter data you want to insert:\n");
    scanf("%d", &num);

    // Find the correct position to insert the new element while maintaining sorted order
    pos = 0;
    while (pos < size && a[pos] < num)
    {
        pos++;
    }

    // Shift elements to make space for the new element
    for (i = size - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }

    // Insert the new element at the correct position
    a[pos] = num;
    size++;

    printf("Output array after insertion:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}