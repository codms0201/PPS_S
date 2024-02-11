#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(TreeNode *root, int *diameter) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);

    *diameter = max(*diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    height(root, &diameter);
    return diameter;
}

TreeNode *createNode(int val) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int result = diameterOfBinaryTree(root);

    printf("Output: %d\n", result);

    return 0;
}
