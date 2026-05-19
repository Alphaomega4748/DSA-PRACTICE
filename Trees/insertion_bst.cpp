/*
========================================================
Problem: Insert into a Binary Search Tree
========================================================

Approach:
----------
We use BST property:

left subtree < root < right subtree

Starting from root:
- If value is smaller than current node,
  move LEFT.

- If value is greater than current node,
  move RIGHT.

We keep traversing until we find an empty position.
Then insert the new node there.

--------------------------------------------------------

Logic:
------
1. If tree is empty:
      create new node and return it.

2. Start traversal from root.

3. If val < current node:
      move LEFT

4. Else:
      move RIGHT

5. When NULL position found:
      insert new node

--------------------------------------------------------

Dry Run:
--------
Insert value = 8

Initial BST:

            10
           /  \
          5    15
         /
        2


Step 1:
current = 10

8 < 10
Move LEFT

current = 5


Step 2:
8 > 5
Move RIGHT

RIGHT is NULL

Insert 8 here


Final BST:

            10
           /  \
          5    15
         / \
        2   8

--------------------------------------------------------

Time Complexity:
Average  : O(log n)
Worst    : O(n)    // skewed BST

Space Complexity:
O(1)     // iterative approach

========================================================
*/


#include <bits/stdc++.h>
using namespace std;


// Definition of BST Node
struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() {

        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x) {

        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {

        val = x;
        this->left = left;
        this->right = right;
    }
};




class Solution {

public:

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree empty
        if(root == NULL) {

            return new TreeNode(val);
        }

        // Start traversal
        TreeNode* cur = root;


        while(true) {

            // Move LEFT
            if(cur->val > val) {

                // Left child exists
                if(cur->left != NULL) {

                    cur = cur->left;
                }

                // Insert here
                else {

                    cur->left = new TreeNode(val);

                    break;
                }
            }

            // Move RIGHT
            else {

                // Right child exists
                if(cur->right != NULL) {

                    cur = cur->right;
                }

                // Insert here
                else {

                    cur->right = new TreeNode(val);

                    break;
                }
            }
        }

        return root;
    }
};




int main() {

    /*
                10
               /  \
              5    15
             /
            2
    */


    // Creating BST manually
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);


    int val = 8;

    Solution obj;

    root = obj.insertIntoBST(root, val);


    cout << "Node inserted successfully" << endl;

    return 0;
}