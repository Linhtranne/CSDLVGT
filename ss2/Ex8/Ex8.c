#include <stdio.h>

int main() {
    int n;
    do {
        scanf("%d", &n);
    } while (n <= 0 || n > 1000);
    int arr[n - 1];
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int totalSum = n * (n + 1) / 2;

    int missingNumber = totalSum - sum;

    printf("So bi thieu la: %d\n", missingNumber);

    return 0;
}
