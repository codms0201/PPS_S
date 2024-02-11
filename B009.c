#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int height(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int isBalanced(TreeNode *root) {
    if (root == NULL) {
        return 1; 
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right)) {
        return 1;
    }

    return 0;
}

TreeNode *createNode(int val) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    TreeNode *root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    int result = isBalanced(root);

    printf(result ? "true\n" : "false\n");

    return 0;
}
