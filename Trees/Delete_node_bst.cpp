/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * 
 *     TreeNode() {
 *         val = 0;
 *         left = NULL;
 *         right = NULL;
 *     }
 * 
 *     TreeNode(int x) {
 *         val = x;
 *         left = NULL;
 *         right = NULL;
 *     }
 * 
 *     TreeNode(int x, TreeNode *left, TreeNode *right) {
 *         val = x;
 *         this->left = left;
 *         this->right = right;
 *     }
 * };
 */



    /*
    ============================================================
    APPROACH
    ============================================================

    We delete a node in BST using 3 cases:

    1. Node has no left child
       -> Return right child

    2. Node has no right child
       -> Return left child

    3. Node has both children
       -> Find rightmost node of left subtree
       -> Attach deleted node's right subtree there
       -> Return left subtree

    Steps:
    - Traverse BST to find target node
    - Use helper() to handle deletion
    - Reconnect updated subtree

    ============================================================
    DRY RUN
    ============================================================

            5
          /   \
         3     6
        / \     \
       2   4     7

    Delete = 3

    Node 3 has both children.

    left subtree  = 2
    right subtree = 4

    Find rightmost node in left subtree:
    -> 2

    Attach:
    2->right = 4

    Return left subtree.

    Final Tree:

            5
          /   \
         2     6
          \      \
           4      7

    ============================================================
    TIME COMPLEXITY
    ============================================================

    Worst Case:
    O(H)

    H = Height of BST

    Skew Tree:
    O(N)

    Balanced BST:
    O(log N)

    ============================================================
    SPACE COMPLEXITY
    ============================================================

    O(H)

    Due to recursive function call stack.

    ============================================================
    */

    #include <iostream>
using namespace std;

// Tree Node
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

class Solution {

public:

    // Delete node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {

        // If tree is empty
        if (root == NULL) {
            return NULL;
        }

        // If root is target node
        if (root->val == key) {
            return helper(root);
        }

        TreeNode* dummy = root;

        while (root != NULL) {

            // Move left
            if (root->val > key) {

                // Target found on left side
                if (root->left != NULL &&
                    root->left->val == key) {

                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }

            // Move right
            else {

                // Target found on right side
                if (root->right != NULL &&
                    root->right->val == key) {

                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }

    // Handle deletion cases
    TreeNode* helper(TreeNode* root) {

        // No left child
        if (root->left == NULL) {
            return root->right;
        }

        // No right child
        if (root->right == NULL) {
            return root->left;
        }

        // Both children exist

        TreeNode* rightChild = root->right;

        TreeNode* lastRight =
        findLastRight(root->left);

        // Attach right subtree
        lastRight->right = rightChild;

        return root->left;
    }

    // Find rightmost node
    TreeNode* findLastRight(TreeNode* root) {

        if (root->right == NULL) {
            return root;
        }

        return findLastRight(root->right);
    }
};

// Inorder Traversal
void inorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
}

int main() {

    /*
            5
          /   \
         3     6
        / \     \
       2   4     7
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    Solution obj;

    int key = 3;

    root = obj.deleteNode(root, key);

    cout << "BST After Deletion: ";

    inorder(root);

    cout << endl;

    return 0;
}