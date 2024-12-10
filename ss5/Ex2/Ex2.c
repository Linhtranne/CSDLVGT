#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = temp;
    return head;
}
void displayList(Node* head) {
    Node* temp = head;
    printf("Danh sách: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (position < 0) {
        printf("Truyen vao vi tri khong hop le.\n");
        free(newNode);
        return head;
    }
    if (position == 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }

    Node* temp = head;
    int index = 0;
    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }
    if (temp == NULL) {
        printf("Truyen vao vi tri khong hop le.\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
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
    int n, value, position;
    printf("Nhap so luong phan tu: ");
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

    printf("Danh sach ban dau:\n");
    displayList(head);
    printf("Nhap gia tri chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri chen: ");
    scanf("%d", &position);
    head = insertAtPosition(head, value, position);
    printf("Danh sach sau khi chen:\n");
    displayList(head);
    freeList(head);

    return 0;
}
