#include <stdio.h>

int main() {
    int n, k, arr[100];
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (int i = 0; i < n; i++) {
        printf(" %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);

    int newSize = n;
    for (int i = 0; i < newSize; ) {
        if (arr[i] == k) {

            for (int j = i; j < newSize - 1; j++) {
                arr[j] = arr[j + 1];
            }
            newSize--;
        } else {
            i++;
        }
    }

    printf("Mang sau khi xoa phan tu %d:\n", k);
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
