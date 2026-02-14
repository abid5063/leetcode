#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution { TreeNode* build(vector<int>& pre, int ps, int pe, vector<int>& in, int is, int ie, unordered_map<int,int>& pos){ if(ps>pe||is>ie) return nullptr; int rootV=pre[ps]; int k=pos[rootV]; int leftLen=k-is; TreeNode* root=new TreeNode(rootV); root->left=build(pre, ps+1, ps+leftLen, in, is, k-1, pos); root->right=build(pre, ps+leftLen+1, pe, in, k+1, ie, pos); return root; } public: TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){ unordered_map<int,int> pos; for(int i=0;i<(int)inorder.size();++i) pos[inorder[i]]=i; return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,pos);} };
