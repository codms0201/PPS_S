#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool findTargetUtil(TreeNode* root, int k, int* nums, int* index) {
    if (root == NULL) {
        return false;
    }

    if (findTargetUtil(root->left, k, nums, index)) {
        return true;
    }

    for (int i = 0; i < *index; i++) {
        if (nums[i] + root->val == k) {
            return true;
        }
    }

    nums[(*index)++] = root->val;

    return findTargetUtil(root->right, k, nums, index);
}

bool findTarget(TreeNode* root, int k) {
    int nums[1000];
    int index = 0;
    return findTargetUtil(root, k, nums, &index);
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->right = createNode(7);

    int k = 9;

    bool result = findTarget(root, k);

    printf(result ? "true\n" : "false\n");

    return 0;
}
