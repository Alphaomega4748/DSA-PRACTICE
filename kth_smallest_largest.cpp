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

For Kth Smallest:

1. Perform inorder traversal
   -> BST inorder gives sorted order

2. Store all elements in vector

3. Return:
   -> values[k-1]

------------------------------------------------------------

For Kth Largest:

1. Same sorted vector is used

2. Return:
   -> values[n-k]

============================================================
DRY RUN
============================================================

                15
               /  \
             10    20
            / \    / \
           8  12  17 25
          / \
         6   9

Inorder Traversal:

6 8 9 10 12 15 17 20 25

Vector:

[6,8,9,10,12,15,17,20,25]

k = 3

Kth Smallest:
values[3-1]
= values[2]
= 9

Kth Largest:
values[9-3]
= values[6]
= 17

Output:
[9,17]

============================================================
TIME COMPLEXITY
============================================================

O(N)

We visit every node once.

============================================================
SPACE COMPLEXITY
============================================================

O(N)

Vector stores all BST elements.

============================================================
*/

class Solution {

public:

    // Inorder Traversal
    void inorderTraversal(TreeNode* node,
                          vector<int>& values) {

        // Base case
        if(node == NULL) {
            return;
        }

        // Left subtree
        inorderTraversal(node->left, values);

        // Store current node
        values.push_back(node->data);

        // Right subtree
        inorderTraversal(node->right, values);
    }

    // Function to find kth smallest and largest
    vector<int> kLargesSmall(TreeNode* root, int k) {

        // Vector to store sorted elements
        vector<int> values;

        // Store BST elements
        inorderTraversal(root, values);

        // Kth smallest
        int kth_smallest = values[k - 1];

        // Kth largest
        int kth_largest =
        values[values.size() - k];

        return {kth_smallest, kth_largest};
    }
};

/*
============================================================
MAIN FUNCTION
============================================================
*/

int main() {

    /*
                    15
                   /  \
                 10    20
                / \    / \
               8  12  17 25
              / \
             6   9
    */

    TreeNode* root = new TreeNode(15);

    root->left = new TreeNode(10);
    root->right = new TreeNode(20);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(12);

    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(25);

    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(9);

    Solution obj;

    int k = 3;

    vector<int> ans =
    obj.kLargesSmall(root, k);

    cout << "Kth Smallest: "
         << ans[0] << endl;

    cout << "Kth Largest: "
         << ans[1] << endl;

    return 0;
}