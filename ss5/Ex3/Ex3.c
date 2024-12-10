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
Node* deleteLastNode(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);

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
    int n, value;
    printf("Nhap so phan tu: ");
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
    head = deleteLastNode(head);
    printf("Danh sach sau khi xoa:\n");
    displayList(head);
    freeList(head);

    return 0;
}
