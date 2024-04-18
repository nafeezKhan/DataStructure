#include <stdio.h>
int main()
{
    int a[50], i, size, pos, item;
    printf("enter size of array:\n");
    scanf("%d", &size);
    printf("enter elements of array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("from what position you want to delete:\n"); // any position we can delete; at begining , at end, at any position
    scanf("%d", &pos);
    if (pos <= 0 || pos > size)
    {
        printf("invalid position\n");
    }
    else
    {
        item = a[pos - 1];
        for (i = pos - 1; i < size - 1; i++)
        {
            a[i] = a[i + 1];
        }
        size--;
    }
    printf("Element %d at position %d deleted successfully.\n", item, pos);
    printf("Output array after deletion:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
