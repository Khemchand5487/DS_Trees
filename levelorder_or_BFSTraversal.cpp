//level order or BFS traversal of a binary tree in c++

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

//level order or BFS traversal of binary tree 
void levelorder(Node *root)
{
    if(root==NULL) return;
    
    queue<Node*> q;
    vector<int> res;
    
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        res.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
    //printing result 
    for(int i:res)
    {
        cout<<i<<" ";
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
    
    //level order traversal
    levelorder(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/