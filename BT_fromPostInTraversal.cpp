/*
Problem title: Construct binary tree from postorder and inorder traversals in c++
Problem name: Construct Binary Tree from Inorder and Postorder Traversal
problem link:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> in;
        int n = inorder.size();
        for(int i=0;i<n;i++)
        {
            in[inorder[i]] = i;
        }
        
        TreeNode* root = build(inorder, 0, n-1, postorder, 0, n-1, in);
        
        return root;
    }
    
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int>& in)
    {
        if(inStart > inEnd || postStart >  postEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int rIdx = in[root->val];
        int nodesNumber = rIdx - inStart;
        
        root->left = build(inorder, inStart, rIdx-1, postorder, postStart, postStart+nodesNumber -1 , in);
        root->right = build(inorder, rIdx+1, inEnd, postorder, postStart+nodesNumber, postEnd-1, in);
        
        return root;
    }
};
