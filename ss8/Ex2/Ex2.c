#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    char direction;
    printf(" %d (L/R)? ", root->data);
    scanf(" %c", &direction);
    if (direction == 'L' || direction == 'l') {
        root->left = insertNode(root->left, data);
    } else if (direction == 'R' || direction == 'r') {
        root->right = insertNode(root->right, data);
    } else {
        printf("Chỉ nhập 'L' hoặc 'R'!\n");
    }
    return root;
}

void findLevel2Nodes(Node* root, int level, int currentLevel) {
    if (root == NULL) {
        return;
    }
    if (currentLevel == level) {
        printf("%d ", root->data);
        return;
    }
    findLevel2Nodes(root->left, level, currentLevel + 1);
    findLevel2Nodes(root->right, level, currentLevel + 1);
}

int hasLevel2Nodes(Node* root, int level, int currentLevel) {
    if (root == NULL) {
        return 0;
    }
    if (currentLevel == level) {
        return 1;
    }
    return hasLevel2Nodes(root->left, level, currentLevel + 1) || 
           hasLevel2Nodes(root->right, level, currentLevel + 1);
}

int main() {
    Node* root = NULL;
    int n, value;

    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Cây rỗng, không có đỉnh lớp 2.\n");
        return 0;
    }

    printf("Nhập giá trị cho nút gốc: ");
    scanf("%d", &value);
    root = createNode(value);

    for (int i = 1; i < n; i++) {
        printf("Nhập giá trị cho nút mới: ");
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Các đỉnh lớp 2: ");
    if (hasLevel2Nodes(root, 2, 0)) {
        findLevel2Nodes(root, 2, 0);
    } else {
        printf("Không có đỉnh lớp 2.");
    }
    printf("\n");

    return 0;
}
