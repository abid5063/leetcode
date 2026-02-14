#include <bits/stdc++.h>
using namespace std;
struct TreeNode{int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };
class Codec {
public:
    string serialize(TreeNode* root){ if(!root) return "#"; string res; queue<TreeNode*> q; q.push(root); while(!q.empty()){ TreeNode* n=q.front(); q.pop(); if(!n){ res += "#,"; continue; } res += to_string(n->val)+","; q.push(n->left); q.push(n->right);} return res; }
    TreeNode* deserialize(string data){ if(data=="#") return nullptr; vector<string> tok; string cur; for(char c: data){ if(c==','){ tok.push_back(cur); cur.clear(); } else cur.push_back(c);} if(!cur.empty()) tok.push_back(cur);
        if(tok.empty()) return nullptr; int i=0; auto make=[&](const string& s)->TreeNode*{ return s=="#"?nullptr:new TreeNode(stoi(s)); };
        TreeNode* root = make(tok[i++]); queue<TreeNode*> q; q.push(root);
        while(!q.empty() && i<(int)tok.size()){
            TreeNode* n=q.front(); q.pop(); if(!n) continue; n->left=make(tok[i++]); n->right= i<(int)tok.size()? make(tok[i++]): nullptr; q.push(n->left); q.push(n->right);
        }
        return root;
    }
};
