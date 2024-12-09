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

int searchNode(Node* head, int value) {
    Node* temp = head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void printList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("Danh sach rong.\n");
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
    int n, value, searchValue;
    printf("So luong phan tu ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("nhap sai roi\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Nhậap gia tri %d: ", i + 1);
        scanf("%d", &value);
        head = appendNode(head, value);
    }
    printf("Danh sach: ");
    printList(head);

    printf("Nhap gia tri: ");
    scanf("%d", &searchValue);

    int result = searchNode(head, searchValue);

    if (result != -1) {
        printf("Tim thay gia tri %d tai vi tri %d.\n", searchValue, result);
    } else {
        printf("Khong tim thay gia tri %d\n", searchValue);
    }
    freeList(head);

    return 0;
}
