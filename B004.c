#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool isMirror(TreeNode* leftSubtree, TreeNode* rightSubtree) {
    if (leftSubtree == NULL && rightSubtree == NULL) {
        return true;
    }

    if (leftSubtree == NULL || rightSubtree == NULL) {
        return false;
    }

    return (leftSubtree->val == rightSubtree->val) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return isMirror(root->left, root->right);
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(2);
    root->left->left = createNode(3);
    root->left->right = createNode(4);
    root->right->left = createNode(4);
    root->right->right = createNode(3);

    bool result = isSymmetric(root);

    printf(result ? "true\n" : "false\n");

    return 0;
}
