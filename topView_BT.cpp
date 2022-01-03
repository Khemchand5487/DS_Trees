//Top view of a binary tree in c++

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

//top view of binary tree 
void topView(Node *root)
{
    if(!root) return;
    
    map<int, int> m; //map(vertical, node)
    queue<pair<Node*, int>> q; //q(node, vertical)
    q.push({root, 0});
    
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int x = temp.second;
        if(m.find(x) == m.end()) m[x] = temp.first->data;
        if(temp.first->left) q.push({temp.first->left, x-1});
        if(temp.first->right) q.push({temp.first->right, x+1});
    }
    for(auto i: m)
    {
        cout<<i.second<<" ";
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
    
    //top view of tree
    topView(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/
