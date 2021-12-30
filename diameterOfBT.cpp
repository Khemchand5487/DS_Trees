// Find diameter of binary tree in c++;

// Leetcode problem link: https://leetcode.com/problems/diameter-of-binary-tree/

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

int util(Node* root, int& mx)
{
    if(root == NULL) return 0;
    
    int lh = util(root->left, mx);
    int rh = util(root->right, mx);
    
    mx = max(mx, lh+rh);
    
    return 1+max(lh, rh);
}

//find diameter of binary tree
int diameterOfBinaryTree(Node* root) 
{
    int mx = 0;
    util(root, mx);
    return mx;
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
    
    //check tree is Balanced or not
    cout<<"Diameter of the tree is: "<<diameterOfBinaryTree(root)<<endl;
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
