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

class Solution {
public:

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

    TreeNode* deleteNode(TreeNode* root, int key) {

        // If tree is empty
        if(root == NULL) {
            return NULL;
        }

        // If root itself is target node
        if(root->val == key) {
            return helper(root);
        }

        // Store original root
        TreeNode* dummy = root;

        // Traverse BST
        while(root != NULL) {

            // Move towards left side
            if(root->val > key) {

                // Target node found at left child
                if(root->left != NULL &&
                   root->left->val == key) {

                    // Delete node and reconnect subtree
                    root->left = helper(root->left);

                    break;
                }
                else {
                    root = root->left;
                }
            }

            // Move towards right side
            else {

                // Target node found at right child
                if(root->right != NULL &&
                   root->right->val == key) {

                    // Delete node and reconnect subtree
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

    // Handles all deletion cases
    TreeNode* helper(TreeNode* root) {

        // Case 1:
        // No left child
        if(root->left == NULL) {
            return root->right;
        }

        // Case 2:
        // No right child
        else if(root->right == NULL) {
            return root->left;
        }

        // Case 3:
        // Both children exist

        // Store right subtree
        TreeNode* rightChild = root->right;

        // Find rightmost node of left subtree
        TreeNode* lastRight =
        findLastRight(root->left);

        // Attach right subtree
        lastRight->right = rightChild;

        // Return left subtree
        return root->left;
    }

    // Find rightmost node
    TreeNode* findLastRight(TreeNode* root) {

        // Rightmost node found
        if(root->right == NULL) {
            return root;
        }

        return findLastRight(root->right);
    }
};