// Find maximum depth or height of the binary tree in c++;

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

//find height or maximum depth of binary tree
int maxDepth(Node* root) 
{
    if(root == NULL) return 0;
    else return (1+max(maxDepth(root->left), maxDepth(root->right)));
        
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
    
    //maximum height of tree
    cout<<"Height or maximum depth of the Binary Tree: "<<maxDepth(root)<<endl;
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
