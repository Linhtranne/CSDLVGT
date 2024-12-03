#include <stdio.h>

int main() {
    int n, k, arr[1000];
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 1000);

    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap k: ");
    scanf("%d", &k);

    printf("Cac cap so co tong  %d la:\n", k);
    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                printf("(%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong co cap so nao%d.\n", k);
    }

    return 0;
}
