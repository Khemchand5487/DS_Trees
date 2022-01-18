/*
Problem title: Serialize and Deserialize Binary Tree in c++
Problem name: Serialize and Deserialize Binary Tree
problem link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL) res.append("#,");
            else res.append(to_string(temp->val)+',');
            if(temp!= NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            getline(s, str, ',');
            if(str == "#")
            {
                temp->left = NULL;
            }
            else
            {
                TreeNode* nn = new TreeNode(stoi(str));
                q.push(nn);
                temp->left = nn;
            }
            
            getline(s, str, ',');
            if(str == "#")
            {
                temp->right = NULL;
            }
            else
            {
                TreeNode* nn = new TreeNode(stoi(str));
                q.push(nn);
                temp->right = nn;
            }
        }
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
