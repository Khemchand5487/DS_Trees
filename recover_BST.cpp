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
    TreeNode* first=NULL, *mid=NULL, *last=NULL, *prev=NULL;
    void bfs(TreeNode* root)
    {
        if(!root) return;
        
        bfs(root->left);
        
        if(prev && (root->val<prev->val))
        {
            if(!first)
            {
                first = prev;
                mid = root;
            }
            else last = root;
        }
        prev = root;
        bfs(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        bfs(root);
        if(!last) last = mid;
        if(first && last) swap(first->val, last->val);
    }
};
