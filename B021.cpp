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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        inorderTraversalRecursive(root, result);
        return result;
    }

private:
    void inorderTraversalRecursive(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        inorderTraversalRecursive(root->left, result);
        result.push_back(root->val);
        inorderTraversalRecursive(root->right, result);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    std::vector<int> result = solution.inorderTraversal(root);

    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
