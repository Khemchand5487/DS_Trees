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
class BTSiterator {
    stack<TreeNode*> st;
    bool reverse = false;
    void pushAll(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            if(reverse) root=root->right;
            else root = root->left;
        }
    }
    public:
        BTSiterator(TreeNode* root, bool isReverse)
        {
            reverse = isReverse;
            pushAll(root);
        }
    
        int next()
        {
            TreeNode *temp = st.top();
            st.pop();
            if(reverse) pushAll(temp->left);
            else pushAll(temp->right);
            return temp->val;
        }
    
        bool hasNext()
        {
            return !st.empty();
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BTSiterator l(root, false);
        BTSiterator r(root, true);
        
        int i=l.next(), j = r.next();
        while(i<j)
        {
            if(i+j==k) return true;
            else if(i+j > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
};
