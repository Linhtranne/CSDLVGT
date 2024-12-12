#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
int isEmpty(Node* top) {
    return top == NULL;
}
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Ngan xep rong\n");
        return -1;
    }
    Node* temp = *top;
    int poppedValue = temp->data;
    *top = temp->next;
    free(temp);
    return poppedValue;
}
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return top->data;
}
void printStack(Node* top) {
    if (isEmpty(top)) {
        printf("Ngan xep rong\n");
        return;
    }
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
int main() {
    Node* stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printStack(stack);
    printf("Top: %d\n", peek(stack));
    printf("Peek: %d\n", pop(&stack));
    printStack(stack);
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
    } else {
        printf("Ngan xep khong rong.\n");
    }

    return 0;
}
