#include <iostream>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Mirror check function
bool isMirror(TreeNode* left, TreeNode* right) {
    
    // Case 1: dono NULL
    if (left == NULL && right == NULL)
        return true;

    // Case 2: ek NULL
    if (left == NULL || right == NULL)
        return false;

    // Case 3: value mismatch
    if (left->val != right->val)
        return false;

    // Case 4: recursive mirror check
    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Main symmetric check
bool isSymmetric(TreeNode* root) {
    if (root == NULL)
        return true;

    return isMirror(root->left, root->right);
}

int main() {
    /*
        Example Tree:
              1
            /   \
           2     2
          / \   / \
         3   4 4   3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric\n";
    else
        cout << "Tree is NOT Symmetric\n";

    return 0;
}