/*
Problem title: Construct binary tree from preorder and inorder traversals in c++
Problem name: Construct Binary Tree from Preorder and Inorder Traversal
problem link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in;
        int n = inorder.size();
        for(int i = 0;i<n;i++)
        {
            in[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, in);
        return root;
    }
    
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& in)
    {
        if(inStart > inEnd || preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int rIdx = in[root->val];
        int nodesLeft = rIdx-inStart;
        
        root->left = build(preorder, preStart+1, preStart+nodesLeft, inorder, inStart, rIdx-1, in);
        root->right = build(preorder,preStart+nodesLeft+1, preEnd, inorder, rIdx+1, inEnd, in);
        
        return root;
    }
};
