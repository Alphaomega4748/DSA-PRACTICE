
// Maximum Depth of Binary Tree

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

We find maximum depth using recursion:

1. If node is NULL
   -> Return 0

2. Recursively find:
   -> Left subtree height
   -> Right subtree height

3. Return:
   -> 1 + max(leftHeight, rightHeight)

============================================================
DRY RUN
============================================================

            1
          /   \
         2     3
        / \
       4   5

Step 1:
height(4) = 1

Step 2:
height(5) = 1

Step 3:
height(2)
= 1 + max(1,1)
= 2

Step 4:
height(3) = 1

Step 5:
height(1)
= 1 + max(2,1)
= 3

Maximum Depth = 3

============================================================
TIME COMPLEXITY
============================================================

O(N)

We visit every node once.

============================================================
SPACE COMPLEXITY
============================================================

O(H)

H = Height of tree
Recursive stack space.

============================================================
*/

class Solution {

public:

    // Function to find maximum depth
    int maxDepth(TreeNode* root) {

        // Base case
        if(root == NULL) {
            return 0;
        }

        // Find left subtree height
        int leftHeight =
        maxDepth(root->left);

        // Find right subtree height
        int rightHeight =
        maxDepth(root->right);

        // Return maximum depth
        return 1 +
        max(leftHeight, rightHeight);
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main() {

    /*
                1
              /   \
             2     3
            / \
           4   5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    int depth = obj.maxDepth(root);

    cout << "Maximum Depth of Binary Tree: "
         << depth << endl;

    return 0;
}