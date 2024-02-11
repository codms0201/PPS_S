#include <iostream>
#include <vector>

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

TreeNode* buildBST(std::vector<int>& preorder, int& index, int minValue, int maxValue) {
    if (index == preorder.size()) {
        return nullptr;
    }

    int currentValue = preorder[index];
    if (currentValue < minValue || currentValue > maxValue) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(currentValue);
    index++;

    root->left = buildBST(preorder, index, minValue, currentValue - 1);
    root->right = buildBST(preorder, index, currentValue + 1, maxValue);

    return root;
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    std::cout << root->key << "\n";
}

int main() {
    std::vector<int> preorder;
    int inputValue;

    while (std::cin >> inputValue) {
        preorder.push_back(inputValue);
    }

    int index = 0;
    TreeNode* root = buildBST(preorder, index, -1e9, 1e9);

    postorderTraversal(root);

    delete root;

    return 0;
}
