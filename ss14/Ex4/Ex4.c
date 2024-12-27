#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6 ,5 ,3 ,4 ,2 ,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng trước khi sắp xếp: \n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Mảng sau khi sắp xếp: \n");
    printArray(arr, n);

    return 0;
}
