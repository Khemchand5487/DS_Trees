// Bounary traversal of binary tree in c++;

// Problem link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#

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

//check if node is leaf node or not
bool isLeaf(Node* root)
{
    return (!root->right && !root->left);
}

//traverse the left view
void left(Node* root, vector<int>& res)
{
    Node * curr =  root->left;
    while(curr)
    {
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
    
//traverse the bottom view of leaf
void leaf(Node *root, vector<int>& res)
{
    if(isLeaf(root)){ 
        res.push_back(root->data); 
        return;
        
    }
     
    if(root->left) leaf(root->left, res);
    if(root->right) leaf(root->right, res);
}

//traverse the right view in reverse order
void right(Node* root, vector<int>& res)
{
    Node*curr = root->right;
    stack<int> s;
    while(curr)
    {
        if(!isLeaf(curr)) s.push(curr->data);
        
        if(curr->right) curr = curr->right;
        else curr= curr->left;
    }
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
}

//anti clockwise boundary traversal
void boundary(Node *root)
{
    vector<int> res;
    if(!root) return;
    if(!isLeaf(root)) res.push_back(root->data);
    left(root, res);
    leaf(root, res);
    right(root, res);
    
    for(int i:res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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
    
    cout<<"Anti clockwise Traversal: "<<endl;
    boundary(root);
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
