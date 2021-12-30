// Check that tree is height balaneced or not in c++;

// Leetcode problem link: https://leetcode.com/problems/balanced-binary-tree/

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

//if tree is balaneced then return height of tree lese return -1
int check(Node *root)
{
    if(root == NULL) return 0;
    
    int lh = check(root->left);
    int rh = check(root->right);
    
    if((lh == -1 || rh==-1) || (abs(lh-rh) >1)) return -1;
    
    return 1+max(lh, rh);
}
    
bool isBalanced(Node* root) {
    return check(root)!=-1;
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
    isBalanced(root)? cout<<"Tree is Balanced!\n" : cout<<"Tree is not Balanced!\n";
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
