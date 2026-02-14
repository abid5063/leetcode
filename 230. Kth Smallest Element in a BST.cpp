#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Solution { public: int kthSmallest(TreeNode* root, int k){ stack<TreeNode*> st; TreeNode* cur=root; while(cur||!st.empty()){ while(cur){ st.push(cur); cur=cur->left; } cur=st.top(); st.pop(); if(--k==0) return cur->val; cur=cur->right; } return -1; } };
