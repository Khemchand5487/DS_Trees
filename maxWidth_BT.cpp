// Maximum width of binary tree in c++;

// Problem link: https://leetcode.com/problems/maximum-width-of-binary-tree/

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

int widthOfBinaryTree(Node* root) 
{
    int width = 0, f, l;
    if(!root) return width;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty())
    {
        int size = q.size();
        int mn = q.front().second;
        for(int i=0;i<size;i++)
        {
            int curr = q.front().second - mn;
            Node* temp = q.front().first;
            q.pop();
            if(i==0) f=curr;
            if(i==size-1) l = curr;
            if(temp->left) q.push({temp->left, 2*curr+1});
            if(temp->right) q.push({temp->right, 2*curr+2});
        }
        width = max(width, l-f+1);
    }
    
    return width;
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
    
    //print maximum width
    cout<<widthOfBinaryTree(root);
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
