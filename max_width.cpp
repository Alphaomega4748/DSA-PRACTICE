#include <iostream>
#include <queue>
using namespace std;

// Problem: Maximum Width of Binary Tree
// Platform: LeetCode / GFG

/*
Approach:
We use Level Order Traversal (BFS) and assign an index to each node
as if the tree is a complete binary tree.

Rules:
- Root index = 0
- Left child = 2*i + 1
- Right child = 2*i + 2

At each level:
- We store first (leftmost) and last (rightmost) node index
- Width = last - first + 1

To avoid overflow:
- We normalize indices at each level by subtracting the minimum index (mmin)
- cur_id = index - mmin

Key Idea:
We don't count nodes, we count positions (including NULL gaps)

Time Complexity: O(n)
- Each node is visited once

Space Complexity: O(n)
- Queue stores nodes level by level
*/

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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    long long ans = 0;

    // queue stores (node, index)
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});

    while (!q.empty()) {

        int size = q.size();

        // minimum index of this level (for normalization)
        long long mmin = q.front().second;

        long long first, last;

        for (int i = 0; i < size; i++) {

            auto curr = q.front();
            q.pop();

            // normalize index to avoid overflow
            long long cur_id = curr.second - mmin;

            // store first and last index of level
            if (i == 0) first = cur_id;
            if (i == size - 1) last = cur_id;

            // push children with calculated indices
            if (curr.first->left)
                q.push({curr.first->left, cur_id * 2 + 1});

            if (curr.first->right)
                q.push({curr.first->right, cur_id * 2 + 2});
        }

        // calculate width of current level
        ans = max(ans, last - first + 1);
    }

    return (int)ans;
}

int main() {

    /*
            1
          /   \
         2     3
        /       \
       4         7

    Expected Width = 4
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Maximum Width: " << widthOfBinaryTree(root);

    return 0;
}