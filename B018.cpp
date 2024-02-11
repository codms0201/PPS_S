#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        targetSum -= root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution solution;
    int targetSum = 22;
    bool result = solution.hasPathSum(root, targetSum);

    std::cout << (result ? "true" : "false") << std::endl;

    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
