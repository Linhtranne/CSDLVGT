#include <stdio.h>

int sumArray(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return arr[0] + sumArray(arr + 1, n - 1);
}

int main()
{
    int arr[100];
    int n, i;
    do
    {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (i = 0; i < n; i++)
    {
        printf(" %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int sum = sumArray(arr, n);

    printf("Tong cac phan tu trong mang la: %d\n", sum);

    return 0;
}