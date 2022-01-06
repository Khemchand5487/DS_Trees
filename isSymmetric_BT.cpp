// Check that tree is symmetric or not in c++;

// Leetcode problem link: https://leetcode.com/problems/symmetric-tree/

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

bool util(Node* left, Node* right)
{
    if(!left || !right) return left==right;
    
    if(left->data != right->data) return false;
    
    return util(left->left, right->right) & util(left->right, right->left);
}

bool isSymmetric(Node* root) {
    if(!root) return false;
    
    return util(root->left, root->right);
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
    
    //check tree is symmetric or not
    isSymmetric(root)? cout<<"Tree is symmetric!\n" : cout<<"Tree is not symmetric!\n";
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
