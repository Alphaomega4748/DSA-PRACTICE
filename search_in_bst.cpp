/*
========================================================
Problem: Search in BST
========================================================

Approach:
----------
BST follows:

left < root < right

Logic:
------
1. If target value smaller than current node
      move LEFT

2. If target value greater than current node
      move RIGHT

3. Repeat until:
      value found
      OR
      root becomes NULL

We traverse only one path in BST.

--------------------------------------------------------
Time Complexity:
Average  : O(log n)
Worst    : O(n)   // skewed BST

Space Complexity:
O(1)  // iterative approach
========================================================
*/


#include <bits/stdc++.h>
using namespace std;


// Definition of BST Node
class TreeNode {

public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) {

        val = x;
        left = NULL;
        right = NULL;
    }
};




class Solution {

public:

    TreeNode* searchBST(TreeNode* root, int target) {


        // Traverse BST
        while(root != NULL && root->val != target) {

            /*
            ------------------------------------------------
            DRY RUN EXAMPLE:
            target = 7

                        10
                       /  \
                      5    15
                     / \
                    2   7

            ------------------------------------------------
            */


            // Move LEFT
            if(target < root->val) {

                /*
                Example:
                target = 7
                root = 10

                7 < 10

                Move LEFT
                */

                root = root->left;
            }

            // Move RIGHT
            else {

                /*
                Example:
                target = 7
                root = 5

                7 > 5

                Move RIGHT
                */

                root = root->right;
            }
        }


        /*
        If found:
        returns node address

        If not found:
        returns NULL
        */

        return root;
    }
};




int main() {

    /*
                    10
                   /  \
                  5    15
                 / \
                2   7
    */


    // Creating BST manually
    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);


    int target = 7;

    Solution obj;

    TreeNode* ans = obj.searchBST(root, target);


    if(ans != NULL)
        cout << "Value Found: " << ans->val << endl;

    else
        cout << "Value Not Found" << endl;


    return 0;
}