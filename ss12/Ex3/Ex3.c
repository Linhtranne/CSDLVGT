#include <stdio.h>

void find(int arr[], int n) {
    int found = 0;

    printf("\nCac cap phan tu doi xung la:\n");
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - i - 1]) {
            printf("(%d, %d)\n", arr[i], arr[n - i - 1]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co phan tu doi xung trong mang\n");
    }
}
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
    find(arr, n);

    return 0;
}