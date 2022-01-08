//print all the nodes at distnace K from a target node in c++
//Problem Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
//Leetcode Problem name: 863. All Nodes Distance K in Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
            {
                parents[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                parents[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(!root || !target) return res;
        if(!k)
        {
            res.push_back(target->val);
            return res;
        }
        
        int isVisited[500] = {0};
        unordered_map<TreeNode*, TreeNode*> parents;
        bfs(root, parents);
        
        queue<TreeNode*> q;
        q.push(target);
        isVisited[target->val] = 1;
        while(k!=0 && !q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !isVisited[temp->left->val])
                {
                    isVisited[temp->left->val] = 1;
                    q.push(temp->left);
                }
                if(temp->right && !isVisited[temp->right->val])
                {
                    isVisited[temp->right->val] = 1;
                    q.push(temp->right);
                }
                if(parents.find(temp) != parents.end() && !isVisited[parents[temp]->val])
                {
                    isVisited[parents[temp]->val] = 1;
                    q.push(parents[temp]);
                }
            }
            k--;
        }
        
        while(!q.empty())
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};
