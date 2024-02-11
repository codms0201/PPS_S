#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }

private:
    int depth(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = depth(node->left, diameter);
        int rightDepth = depth(node->right, diameter);

        diameter = std::max(diameter, leftDepth + rightDepth);

        return 1 + std::max(leftDepth, rightDepth);
    }
};

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = solution.diameterOfBinaryTree(root);

    std::cout << "Output: " << result << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
