// Problem (short):
// Given a binary search tree, return its kth smallest value.

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
    void buildInorder(TreeNode *node, vector<int> &inorderVals)
    {
        if (!node)
            return;
        buildInorder(node->left, inorderVals);
        inorderVals.push_back(node->val);
        buildInorder(node->right, inorderVals);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> inorderVals;
        buildInorder(root, inorderVals);
        if (k < 1 || k > (int)inorderVals.size())
            return -1;
        return inorderVals[k - 1];
    }
};
