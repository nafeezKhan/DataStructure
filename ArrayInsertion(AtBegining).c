#include <stdio.h>
int main()
{
    int a[50], size, i, num, pos;
    printf("enter size of array:\n");
    scanf("%d", &size);
    printf("enter elements of array:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter data you want to insert:\n");
    scanf("%d", &num);
    printf("enter position:\n");
    scanf("%d", &pos);
    for (i = size - 1; i >=0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = num;
    size++;
    printf("Output array after insertion:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
