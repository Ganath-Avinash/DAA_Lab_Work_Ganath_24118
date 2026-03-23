//Ganath Avinash CH.SC.U4CSE24118

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int data;
    int color;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node *root = NULL;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

void leftRotate(Node *x) {
    Node *y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node *y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void fixInsert(Node *z) {
    while (z != root && z->parent != NULL && z->parent->color == RED) {

        if (z->parent == z->parent->parent->left) {
            Node *uncle = z->parent->parent->right;

            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            Node *uncle = z->parent->parent->left;

            if (uncle != NULL && uncle->color == RED) {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void insert(int data) {
    Node *z = createNode(data);
    Node *parent = NULL;
    Node *curr = root;

    while (curr != NULL) {
        parent = curr;
        if (z->data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    z->parent = parent;

    if (parent == NULL)
        root = z;
    else if (z->data < parent->data)
        parent->left = z;
    else
        parent->right = z;

    fixInsert(z);
}

int height(Node *node) {
    if (node == NULL) return 0;
    int hl = height(node->left);
    int hr = height(node->right);
    return (hl > hr ? hl : hr) + 1;
}

void printLevel(Node *node, int targetLevel, int currLevel) {
    if (node == NULL) {
        if (currLevel == targetLevel) printf("   ");
        return;
    }

    if (currLevel == targetLevel) {
        printf("%d(%c) ", node->data, node->color == RED ? 'R' : 'B');
        return;
    }

    printLevel(node->left, targetLevel, currLevel + 1);
    printLevel(node->right, targetLevel, currLevel + 1);
}

void levelOrder() {
    int h = height(root);
    printf("\nLevel Order Traversal:\n");

    for (int i = 0; i < h; i++) {
        printf("Level %d: ", i);
        printLevel(root, i, 0);
        printf("\n");
    }
}

void inorder(Node *node) {
    if (node == NULL) return;

    inorder(node->left);
    printf("%d(%c) ", node->data, node->color == RED ? 'R' : 'B');
    inorder(node->right);
}

int main() {
    int keys[] = {157, 110, 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Red-Black Tree Insertion\n");
    printf("Inserting values: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", keys[i]);
        insert(keys[i]);
    }

    printf("\n\nInorder Traversal:\n");
    inorder(root);

    printf("\n");
    levelOrder();

    return 0;
}
