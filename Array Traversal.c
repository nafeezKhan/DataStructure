#include <stdio.h>
int main()
{
    int a[50], size, i;
    printf("enter size of array:\n");
    scanf("%d", &size);
    printf("enter the elements of array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("elements in array are:\n");
    for (i = 0; i < size; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
