#include <stdio.h>

int C(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return C(n - 1, k - 1) + C(n - 1, k);
}

int main() {
    int n, k;

    printf("Nhap n: ");
    scanf("%d", &n);

    printf("Nhap k: ");
    scanf("%d", &k);

    printf("%d", C(n, k));

    return 0;
}