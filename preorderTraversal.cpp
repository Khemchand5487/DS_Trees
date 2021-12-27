//preorder traversal of a binary tree using recursion in c++

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

//pre-order(Root Left Right) traversal of binary tree 
void preorder(Node *root)
{
    if(root==NULL) return;
    
    cout<<root->data<<" "; //printing root node
    
    preorder(root->left); //traversing left subtree
    preorder(root->right); //traversing right subtree
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
    
    //preorder traversal
    preorder(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/
