#include <iostream>
#include <stack>
#include <string>

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data) : data(data), left(nullptr), right(nullptr) {}
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

TreeNode* constructExpressionTree(const std::string& prefixExpression) {
    std::stack<TreeNode*> stack;

    for (int i = prefixExpression.size() - 1; i >= 0; i--) {
        char c = prefixExpression[i];

        TreeNode* node = new TreeNode(c);

        if (isOperator(c)) {
            node->left = stack.top();
            stack.pop();
            node->right = stack.top();
            stack.pop();
        }

        stack.push(node);
    }

    return stack.top();
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    std::stack<TreeNode*> stack;
    stack.push(root);
    std::string result;

    while (!stack.empty()) {
        TreeNode* current = stack.top();
        stack.pop();

        result = current->data + result;

        if (current->left)
            stack.push(current->left);
        if (current->right)
            stack.push(current->right);
    }

    std::cout << "Post-order traversal: " << result << std::endl;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main() {
    std::string prefixExpression;
    std::cout << "Enter the prefix expression: ";
    std::getline(std::cin, prefixExpression);

    TreeNode* root = constructExpressionTree(prefixExpression);

    postOrderTraversal(root);

    deleteTree(root);

    return 0;
}
