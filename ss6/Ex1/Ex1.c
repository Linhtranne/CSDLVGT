#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int value) {
    if (isFull()) {
        printf("Ngan xep day.\n");
        return;
    }
    stack[++top] = value;
}
int pop() {
    if (isEmpty()) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return stack[top--];
}
void displayStack() {
    if (isEmpty()) {
        printf("Ngan xep rong.\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, value;
    printf("Nhap so luong phan tu \n");
    scanf("%d", &n);

    if (n < 0 || n > MAX_SIZE) {
        printf("Nhap sai roi\n");
        return 1;
    }
    printf("Nhap cac phan tu");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    displayStack();
    return 0;
}
