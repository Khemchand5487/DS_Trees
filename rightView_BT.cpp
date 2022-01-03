//Right view of a binary tree in c++

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

void rightView(Node* root, int level, vector<int>& res)
{
    if(!root) return;
    
    if(level == res.size()) res.push_back(root->data);
    
    rightView(root->right, level+1, res);
    rightView(root->left, level+1, res);
}

//Right side view of binary tree 
void rightSideView(Node* root) {
    vector<int> res;
    if(!root) return;
    rightView(root,0, res);
    
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
    
    //right view of tree
    rightSideView(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/
