#include <stdio.h>
int sum(int n, int m) {
    if (n > m) { 
        return 0;
    }
    return n + sum(n + 1, m);
}
int main() {
    int n, m;
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Nhap m (m > n): ");
        scanf("%d", &m);
    } while (n >= m);

    printf("Tong cac so tu %d đen %d la: %d\n", n, m, sum(n, m));

    return 0;
}
