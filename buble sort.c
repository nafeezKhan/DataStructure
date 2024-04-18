#include<stdio.h>
int main()
{
    int n, i, j,temp;
    scanf("%d", &n);
    int a[n];
    for ( i = 0; i <n; i++)
    {
        scanf("%d", &a[i]);
    }
    for ( j = 0; j <n-1; j++)
    {
        for ( i = 0; i <n-1; i++)
        {
            if (a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            
        }
        
        
    }
    printf("Sorted array:\n ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    
    return 0;
}
