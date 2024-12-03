#include <stdio.h>

int main() {
    int n, i, a;
    int arr[100];
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    for (i = 0; i < n; i++) {
        printf(" %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    printf("Nhap phan  tu can tim \n");
    scanf("%d \n", &a);
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            flag++;
        }
    }
    printf("phan tu can tim co so lan la  %d\n", flag);

}
