//Vertical order traversal of a binary tree in c++

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

//Vertical order traversal of binary tree 
void verticalTraversal(Node* root) {
    vector<vector<int>> res;
    if(root == NULL) return;
    
    map<int, map<int, multiset<int>>> m; //m(vertical, map(level, nodes values))
    
    queue<pair<Node*, pair<int, int>>> q; // q(node, vertical, level)
    
    q.push({root, {0, 0}});
    
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        
        int x = temp.second.first, y = temp.second.second;
        m[x][y].insert(temp.first->data);
        if(temp.first->left) q.push({temp.first->left, {x-1, y+1}});
        if(temp.first->right) q.push({temp.first->right, {x+1, y+1}});
    }
    
    for(auto i:m)
    {
        vector<int> r;
        for(auto j:i.second)
        {
            r.insert(r.end(), j.second.begin(), j.second.end());
        }
        res.push_back(r);
    }
    for(auto i:res)
    {
        for(int j: i)
        {
            cout<<j<<" "; 
        }
        cout<<endl;
    }
}

int main()
{
    //creating a tree
    struct Node *root = new Node(8);
    
    root->left = new Node(5);
    root->right = new Node(9);
    
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    root->right->right = new Node(2);
    root->right->left = new Node(10);
    //END
    
    //vertical order traversal
    verticalTraversal(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/
