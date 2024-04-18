#include <stdio.h>

int binarysearch(int a[], int n, int data) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (data == a[mid]) {
            return mid;
        } else if (data < a[mid]) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main() {
    int a[10] = {5, 9, 7, 23, 25, 45, 59, 63, 71, 89};
    int data = 59;
    int n = sizeof(a) / sizeof(a[0]);
    int result = binarysearch(a, n, data);
    if (result == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", result);
    return 0;
}

