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
    TreeNode* util(vector<int>& preorder, int& i, int mx)
    {
        if(i==preorder.size() || preorder[i]>mx) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = util(preorder, i, root->val);
        root->right = util(preorder, i, mx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return util(preorder, i, INT_MAX);
    }
};
