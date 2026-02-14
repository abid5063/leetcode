#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution {
    bool same(TreeNode* a, TreeNode* b){ if(!a||!b) return a==b; return a->val==b->val && same(a->left,b->left) && same(a->right,b->right); }
public:
    bool isSubtree(TreeNode* s, TreeNode* t){ if(!s) return false; if(same(s,t)) return true; return isSubtree(s->left,t) || isSubtree(s->right,t); }
};
