// Problem (short):
// Given preorder and inorder traversals, rebuild and return the original binary tree.

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
    // Helper function to recursively build the tree
    // pre[preorderStart..preorderEnd]: preorder range | in[inorderStart..inorderEnd]: inorder range | inorderPos: inorder element->index map
    TreeNode *build(vector<int> &pre, int preorderStart, int preorderEnd, vector<int> &in, int inorderStart, int inorderEnd, unordered_map<int, int> &inorderPos)
    {
        // Base case: if ranges are invalid, no subtree to build
        if (preorderStart > preorderEnd || inorderStart > inorderEnd)
            return nullptr;
        
        // In preorder, FIRST element is always the root of current subtree
        int rootVal = pre[preorderStart];
        
        // Find root's position in inorder to determine left/right split
        int rootInorderIdx = inorderPos[rootVal];
        
        // Count how many nodes are in the left subtree
        int leftLen = rootInorderIdx - inorderStart;
        
        // Create root node
        TreeNode *root = new TreeNode(rootVal);
        
        // Recursively build left subtree:
        // - Preorder: [preorderStart+1, preorderStart+leftLen]  (nodes right after root)
        // - Inorder:  [inorderStart, rootInorderIdx-1]          (nodes left of root)
        root->left = build(pre, preorderStart + 1, preorderStart + leftLen, in, inorderStart, rootInorderIdx - 1, inorderPos);
        
        // Recursively build right subtree:
        // - Preorder: [preorderStart+leftLen+1, preorderEnd]  (remaining nodes after left subtree)
        // - Inorder:  [rootInorderIdx+1, inorderEnd]          (nodes right of root)
        root->right = build(pre, preorderStart + leftLen + 1, preorderEnd, in, rootInorderIdx + 1, inorderEnd, inorderPos);
        
        return root;
    }

public:
    // Main function: construct tree from preorder and inorder traversals
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Preprocess: map each inorder element to its index for O(1) lookup
        unordered_map<int, int> inorderPos;
        for (int i = 0; i < (int)inorder.size(); ++i)
            inorderPos[inorder[i]] = i;
        
        // Start recursive build with full ranges
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderPos);
    }
};
