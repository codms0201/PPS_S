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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        postorderTraversalRecursive(root, result);
        return result;
    }

private:
    void postorderTraversalRecursive(TreeNode* root, std::vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        postorderTraversalRecursive(root->left, result);
        postorderTraversalRecursive(root->right, result);
        result.push_back(root->val);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    std::vector<int> result = solution.postorderTraversal(root);

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
