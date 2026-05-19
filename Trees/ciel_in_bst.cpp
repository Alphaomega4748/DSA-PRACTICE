/*
========================================================
Problem: Ceil in BST
========================================================

Approach:
----------
Ceil of a number = smallest value >= key

BST Property:
left < root < right

Logic:
------
1. If root->data == key
      exact ceil found
      return it

2. If key > root->data
      current node smaller hai
      ceil nahi ho sakta
      move RIGHT

3. Else (key < root->data)
      current node possible ceil hai
      store it
      smaller better ceil left side mai ho sakta hai
      move LEFT

We traverse only one path in BST.

--------------------------------------------------------
Time Complexity:
Average  : O(log n)
Worst    : O(n)   // skewed tree

Space Complexity:
O(1)  // iterative approach
========================================================
*/


#include <bits/stdc++.h>
using namespace std;


// Definition of BST Node
class TreeNode {

public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int val) {

        data = val;
        left = NULL;
        right = NULL;
    }
};



// Function to find Ceil in BST
int findCeil(TreeNode* root, int key) {

    // Stores final ceil answer
    int ceil = -1;


    // Traverse BST
    while(root != NULL) {

        /*
        ------------------------------------------------
        DRY RUN EXAMPLE:
        key = 21

                    25
                   /  \
                 15    40
                   \
                    20
                      \
                       22

        ------------------------------------------------
        */


        // Exact match found
        if(root->data == key) {

            ceil = root->data;

            return ceil;
        }


        // Move RIGHT
        // because current node smaller hai
        if(key > root->data) {

            /*
            Example:
            key = 21
            root = 15

            21 > 15
            ceil nahi ho sakta

            Move RIGHT
            */

            root = root->right;
        }

        // Possible ceil found
        else {

            /*
            Example:
            key = 21
            root = 25

            25 > 21

            Possible ceil:
            ceil = 25

            Better smaller ceil left side mai ho sakta hai
            */

            ceil = root->data;

            // Move LEFT
            root = root->left;
        }
    }

    return ceil;
}



int main() {

    /*
                    25
                   /  \
                 15    40
                /  \
              10   20
                     \
                      22
    */


    // Creating BST manually
    TreeNode* root = new TreeNode(25);

    root->left = new TreeNode(15);
    root->right = new TreeNode(40);

    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(20);

    root->left->right->right = new TreeNode(22);


    int key = 21;

    int ans = findCeil(root, key);

    cout << "Ceil of " << key << " = " << ans << endl;

    return 0;
}