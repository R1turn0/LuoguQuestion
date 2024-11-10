#include <iostream>

struct TreeNode {
    int value;          // 节点的值
    TreeNode* left;     // 指向左子节点的指针
    TreeNode* right;    // 指向右子节点的指针

    // 构造函数，使用 explicit 防止隐式转换
    explicit TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root) {
    if (root == nullptr) return;

    std::cout << root->value << " ";  // 先访问根节点
    preorder(root->left);             // 再访问左子树
    preorder(root->right);            // 最后访问右子树
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;

    inorder(root->left);              // 先访问左子树
    std::cout << root->value << " ";  // 然后访问根节点
    inorder(root->right);             // 最后访问右子树
}

void reverseInorder(TreeNode* root) {
    if (root == nullptr) return;

    reverseInorder(root->right);      // 先访问右子树
    std::cout << root->value << " ";  // 然后访问根节点
    reverseInorder(root->left);       // 最后访问左子树
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Preorder traversal: ";
    preorder(root);  // 输出：1 2 4 5 3
    std::cout << std::endl;

    return 0;
}
