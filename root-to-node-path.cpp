// Problem: Root to Node Path in Binary Tree
// Platform: Custom / GFG style

// Approach:
// We use recursion + backtracking to find path from root to target node.
// At each node:
// 1. Add current node to path
// 2. If current node == target → return true
// 3. Recursively search in left or right subtree
// 4. If target not found → remove current node (backtracking)
// 5. Return true if found in any subtree

// Time Complexity: O(n)  (visit each node once)
// Space Complexity: O(h) (recursion stack + path storage)


#include <iostream>
#include <vector>
using namespace std;

// Tree Node Definition
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

// Function to get path from root to target node
bool getPath(TreeNode *root, vector<int> &arr, int x) {

    if (root == NULL) {
        return false;
    }

    // Push current node
    arr.push_back(root->val);

    // Check if target found
    if (root->val == x) {
        return true;
    }

    // Check left or right
    if (getPath(root->left, arr, x) || 
        getPath(root->right, arr, x)) {
        return true;
    }
    else {
        // 🔥 Backtracking (POP)
        arr.pop_back();
        return false;
    }
}

// Main function
int main() {

    /*
            1
          /   \
         2     3
        / \
       4   5
          / \
         6   7
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    vector<int> path;

    int x;
    cout << "Enter target value: ";
    cin >> x;

    if (getPath(root, path, x)) {
        cout << "Path: ";
        for (int val : path) {
            cout << val << " ";
        }
    } else {
        cout << "Node not found";
    }

    return 0;
}