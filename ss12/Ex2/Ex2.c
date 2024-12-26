#include <stdio.h>

int main() {
    int n, i, min;
    int arr[100];
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (i = 0; i < n; i++) {
        printf(" %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("phan tu nho nhat %d\n", min);

    return 0;
}
