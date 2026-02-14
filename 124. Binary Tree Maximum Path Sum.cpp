#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution { int best; int dfs(TreeNode* n){ if(!n) return 0; int L=max(0, dfs(n->left)); int R=max(0, dfs(n->right)); best=max(best, n->val + L + R); return n->val + max(L,R); } public: int maxPathSum(TreeNode* root){ best=INT_MIN; dfs(root); return best; } };
