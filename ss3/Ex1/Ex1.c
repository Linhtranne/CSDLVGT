#include <stdio.h>
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n;
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
    } while (n < 0);
    printf("Giai thua cua %d la: %lld\n", n, factorial(n));

    return 0;
}
