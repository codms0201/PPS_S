#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        std::vector<int> inorderValues;
        inOrderTraversal(root, inorderValues);

        TreeNode* newRoot = new TreeNode(0);
        TreeNode* current = newRoot;
        for (int value : inorderValues) {
            current->right = new TreeNode(value);
            current = current->right;
        }

        return newRoot->right;
    }

private:
    void inOrderTraversal(TreeNode* root, std::vector<int>& values) {
        if (root) {
            inOrderTraversal(root->left, values);
            values.push_back(root->val);
            inOrderTraversal(root->right, values);
        }
    }
};

void printInOrder(TreeNode* root) {
    if (root) {
        printInOrder(root->left);
        std::cout << root->val << " ";
        printInOrder(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->right->right->left = new TreeNode(7);
    root->right->right->right = new TreeNode(9);

    Solution solution;
    TreeNode* result = solution.increasingBST(root);

    printInOrder(result);

    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
