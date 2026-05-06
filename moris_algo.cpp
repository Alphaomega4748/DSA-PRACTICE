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
}

/*
# Morris Inorder Traversal (Binary Tree)

## Problem

Perform inorder traversal of a binary tree without using recursion or stack.

Inorder Traversal Order:

```text
Left -> Root -> Right
```

---

# Intuition

Normally inorder traversal uses:

* Recursion
* Stack

Both take extra space.

Morris Traversal avoids extra space by:

* Temporarily modifying tree links
* Creating threads from predecessor to current node

This allows us to return back to a node without recursion.

---

# What is Inorder Predecessor?

For a node:

```text
curr
```

Its inorder predecessor is:

```text
Rightmost node in its left subtree
```

Example:

```text
        1
       / \
      2   3
     / \
    4   5
```

For node 1:

* Left subtree rooted at 2
* Rightmost node = 5

So predecessor of 1 = 5

---

# Main Logic

## CASE 1:

If current node has NO left child

```cpp
curr->left == NULL
```

Then:

1. Visit current node
2. Move right

Because inorder says:

```text
Left -> Root -> Right
```

and left subtree does not exist.

---

## CASE 2:

If current node HAS left child

We must:

1. Find predecessor
2. Create temporary thread
3. Move left

Later:

* Remove thread
* Visit node
* Move right

---

# Full Algorithm

For every node:

### If left child does not exist:

```cpp
visit current
move right
```

### Else:

Find predecessor.

#### If predecessor->right == NULL

Means first time visiting current node.

Create thread:

```cpp
pred->right = curr
```

Move left.

---

#### Else if predecessor->right == curr

Means left subtree already traversed.

Now:

1. Remove thread
2. Visit current
3. Move right

---

# Full Code with Comments

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
MORRIS INORDER TRAVERSAL
---------------------------------------------------------

APPROACH:
We perform inorder traversal without recursion
and without stack.

We use threaded binary tree concept.

For every node:

1. If left child does not exist:
      visit node
      move right

2. Else:
      find inorder predecessor

      a) If predecessor right is NULL
            create temporary thread
            move left

      b) Else
            remove thread
            visit current node
            move right

TIME COMPLEXITY:
O(N)

SPACE CO
```

*/