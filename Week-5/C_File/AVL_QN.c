//Ganath Avinash CH.SC.U4CSE24118

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node *node) {
    if (node == NULL) return 0;
    return node->height;
}

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int getBalance(Node *node) {
    if (node == NULL) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node *insertAVL(Node *root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insertAVL(root->left, data);
    else if (data > root->data)
        root->right = insertAVL(root->right, data);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
        return rightRotate(root);

    if (balance < -1 && data > root->right->data)
        return leftRotate(root);

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void levelOrder(Node *root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    Node *queue[200];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int level = 0;

    printf("\nLevel Order Traversal:\n");

    while (front < rear) {
        int levelSize = rear - front;
        printf("Level %d: ", level++);

        for (int i = 0; i < levelSize; i++) {
            Node *curr = queue[front++];
            printf("%d ", curr->data);

            if (curr->left != NULL) queue[rear++] = curr->left;
            if (curr->right != NULL) queue[rear++] = curr->right;
        }
        printf("\n");
    }
}

int isAVL(Node *root) {
    if (root == NULL) return 1;
    int bal = getBalance(root);
    if (bal < -1 || bal > 1) return 0;
    return isAVL(root->left) && isAVL(root->right);
}

int main() {
    Node *root = NULL;

    int values[] = {157, 110, 147, 122, 149, 151, 111, 141, 112, 123, 133, 117};
    int n = sizeof(values) / sizeof(values[0]);

    printf("Inserted values: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = insertAVL(root, values[i]);
    }

    printf("\n");
    levelOrder(root);

    if (isAVL(root))
        printf("\nTree is AVL Balanced\n");
    else
        printf("\nTree is NOT AVL Balanced\n");

    return 0;
}
