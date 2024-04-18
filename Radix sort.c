#include<stdio.h>
int main(int argc, char const *argv[])
{
     radix sort(a,n)
    {
    int pos;
    int max=get max(a,n);
    for ( pos = 1; max/pos>0; pos*10)
    {
        count sort(a,n,pos);
    }
    }
    count sort(int a[], int n,int pos)
    {
        int count[10]={0};
        for ( i = 0; i <n; i++)
        {
            ++count[(a[i])%10];
        }
        for ( i = 1; i <=k; i++)
        {
            count[i]=count[i]+count[i-1];
        }
            for ( i = n-1; i>=0; i--)
            {
                b[--count[(a[i]/pos)%10]]=a[i];
            }
            for ( i = 0; i <n; i++)
            {
                a[i]=b[i];
            }
            
        
    }
    

    return 0;
}
