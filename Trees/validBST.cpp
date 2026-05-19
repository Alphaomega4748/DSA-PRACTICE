#include <bits/stdc++.h>
using namespace std;

/*
============================================================
TREE NODE
============================================================
*/

struct TreeNode {

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {

        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
============================================================
APPROACH
============================================================

We validate BST using range checking:

1. Every node must satisfy:
   -> min < node < max

2. Left subtree:
   -> max becomes current node

3. Right subtree:
   -> min becomes current node

4. If any node violates range
   -> Not a BST

============================================================
DRY RUN
============================================================

            5
          /   \
         3     7
        / \     \
       2   4     8

Root:
Range = (-∞ , +∞)

Node 3:
Range = (-∞ , 5)

Node 7:
Range = (5 , +∞)

Node 2:
Range = (-∞ , 3)

All nodes satisfy range.

Tree is BST.

============================================================
TIME COMPLEXITY
============================================================

O(N)

============================================================
SPACE COMPLEXITY
============================================================

O(H)

H = Height of tree

============================================================
*/

class Solution {

public:

    // Function to check BST
    bool isValidBST(TreeNode* root) {

        return checkBST(root,
                        LONG_MIN,
                        LONG_MAX);
    }

    // Recursive function
    bool checkBST(TreeNode* root,
                  long minValue,
                  long maxValue) {

        // Base case
        if(root == NULL) {
            return true;
        }

        // BST violation
        if(root->data <= minValue ||
           root->data >= maxValue) {

            return false;
        }

        // Check left subtree
        bool left =
        checkBST(root->left,
                 minValue,
                 root->data);

        // Check right subtree
        bool right =
        checkBST(root->right,
                 root->data,
                 maxValue);

        return left && right;
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main() {

    /*
                5
              /   \
             3     7
            / \     \
           2   4     8
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(8);

    Solution obj;

    if(obj.isValidBST(root)) {

        cout << "Valid BST";
    }
    else {

        cout << "Not a BST";
    }

    return 0;
}