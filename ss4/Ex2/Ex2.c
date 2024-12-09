#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
Node* prependNode(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode; 
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int n, value;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Nhap sai roi!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = prependNode(head, value);
    }
    printf("Danh sach sau khi them: ");
    printList(head);
    freeList(head);
    return 0;
}
