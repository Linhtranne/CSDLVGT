#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(char c) {
    if (isFull()) {
        printf("Ngan xep day\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        printf("Ngan xep rong\n");
        return '\0';
    }
    return stack[top--];
}

int main() {
    char input[MAX_SIZE + 1];
    char reversed[MAX_SIZE + 1];
    int i;
    printf("Nhap mot chuoi \n");
    fgets(input, MAX_SIZE + 1, stdin);
    size_t len = strlen(input);
    for (i = 0; i < len; i++) {
        push(input[i]);
    }
    i = 0;
    while (!isEmpty()) {
        reversed[i++] = pop();
    }
    reversed[i] = '\0';

    printf(" %s\n", reversed);

    return 0;
}
