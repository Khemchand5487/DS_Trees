// zigzag level order traversal of binary tree in c++;

// Leetcode problem link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *right, *left;
    
    Node(int val)
    {
        data = val;
        left=right=NULL;
    }
};

void zigzagLevelOrder(Node* root) 
{
    vector<vector<int>> res;
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty())
    {
        
        int n = q.size();
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            Node* temp = q.front();
            int idx = flag? i: (n-1-i);
            v[idx]= temp->data;
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        flag = !flag;
        res.push_back(v);
        
    }
    for(auto i: res)
    {
        for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    struct Node *root = new Node(8);
    
    root->left = new Node(5);
    root->right = new Node(9);
    
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    root->right->right = new Node(2);
    root->right->left = new Node(10);
    
    cout<<"Zig-Zag Traversal: "<<endl;
    zigzagLevelOrder(root);
    return 0;
}

/*
The above code represent a binary tree like below:

                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2

*/
