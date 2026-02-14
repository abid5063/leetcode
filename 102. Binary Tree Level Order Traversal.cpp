#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution { public: vector<vector<int>> levelOrder(TreeNode* root){ vector<vector<int>> res; if(!root) return res; queue<TreeNode*> q; q.push(root); while(!q.empty()){ int sz=q.size(); res.emplace_back(); while(sz--){ TreeNode* n=q.front(); q.pop(); res.back().push_back(n->val); if(n->left) q.push(n->left); if(n->right) q.push(n->right);} } return res; } };
