// Print lowest common ancestor of binary tree in c++;

// Problem link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) 
{
    if(!root || root==p || root==q) return root;
    
    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);
    
    if(!left) return right;
    else if(!right) return left;
    else return root;
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
    
    //print lowestCommonAncestor
    cout<<lowestCommonAncestor(root, root->left->left, root->left->right)->data;
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
