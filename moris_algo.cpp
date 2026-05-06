#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
MORRIS INORDER TRAVERSAL
---------------------------------------------------------

APPROACH:
We perform inorder traversal without using recursion
or stack by temporarily modifying the tree structure.

Inorder:
Left -> Root -> Right

Main Idea:
For every node having a left child:
1. Find its inorder predecessor
   (rightmost node in left subtree)

2. If predecessor->right == NULL
      create temporary thread:
      predecessor->right = current
      move current to left child

3. Else
      thread already exists
      remove thread
      visit current node
      move to right child

Why?
The temporary thread helps us return back to the
current node without recursion or stack.

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(1)
---------------------------------------------------------
*/

// Definition for binary tree node
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        // Start traversal from root
        TreeNode* curr = root;

        while(curr)
        {
            //-------------------------------------------------
            // CASE 1:
            // No left child exists
            //-------------------------------------------------
            if(curr->left == NULL)
            {
                // Visit current node
                ans.push_back(curr->val);

                // Move to right subtree
                curr = curr->right;
            }

            //-------------------------------------------------
            // CASE 2:
            // Left subtree exists
            //-------------------------------------------------
            else
            {
                // Find inorder predecessor
                // (rightmost node in left subtree)
                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }

                //-------------------------------------------------
                // First time visiting current node
                //-------------------------------------------------
                if(pred->right == NULL)
                {
                    // Create temporary thread
                    pred->right = curr;

                    // Move left
                    curr = curr->left;
                }

                //-------------------------------------------------
                // Second time visiting current node
                //-------------------------------------------------
                else
                {
                    // Remove temporary thread
                    pred->right = NULL;

                    // Visit current node
                    ans.push_back(curr->val);

                    // Move right
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5

    Inorder:
    4 2 5 1 3
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    vector<int> ans = obj.inorderTraversal(root);

    cout << "Inorder Traversal: ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}S