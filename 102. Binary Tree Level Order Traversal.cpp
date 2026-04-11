// Problem (short):
// Given a binary tree, return its nodes level by level from left to right.

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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            pair<TreeNode *, int> cur = q.front();
            q.pop();

            TreeNode *node = cur.first;
            int level = cur.second;

            if (level == (int)res.size())
                res.push_back({});

            res[level].push_back(node->val);

            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        return res;
    }
};
