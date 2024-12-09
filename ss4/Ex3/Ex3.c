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

Node* appendNode(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* deleteFirstNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("Khong co phan tu.\n");
        return;
    }
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

    printf("Nhap so phan tu ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Nhap sai roi\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        head = appendNode(head, value);
    }
    printf("Danh sách ban đầu: ");
    printList(head);

    head = deleteFirstNode(head);
    printf("Danh sach sau khi xoa: ");
    printList(head);
    freeList(head);

    return 0;
}
