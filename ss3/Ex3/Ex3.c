#include <stdio.h>
int F(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return F(n - 1) + F(n - 2);
}
int main(){
        int n;
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
    } while (n <= 0);   
    printf("Day Fibonanci voi %d so dau tien:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", F(i));
    }
}