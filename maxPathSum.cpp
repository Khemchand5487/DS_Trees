// Find maximum path sum of any non-empty path of binary tree in c++;

// Leetcode problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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

    int lh = max(0, util(root->left, mx));
    int rh = max(0, util(root->right, mx));

    mx = max(mx, lh+rh+(root->data));

    return( root->data)+max(lh, rh);
}

//maximum path sum of any non-empty path in binary tree
int maxPathSum(Node* root) 
{
    int mx = INT_MIN;
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
    
    cout<<"Maximum Path Sum: "<<maxPathSum(root)<<endl;
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
