// Transform tree to follow children sum property in c++

// Problem link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

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

// generalize solution
void toSumTree1(Node *node)
{
    if(!node) return;
    int child = 0;
    if(node->left) child += node->left->data;
    if(node->right) child += node->right->data;
    
    if(child>=node->data) node->data = child;
    else
    {
        if(node->left) node->left->data = node->data;
        if(node->right) node->right->data = node->data;
    }
    
    toSumTree1(node->left);
    toSumTree1(node->right);
    
    int ttl = 0;
    if(node->left) ttl+=node->left->data;
    if(node->right) ttl+=node->right->data;
    if(node->left || node->right) node->data = ttl;
}
//END

//problem solution
int util(Node* root)
{
    if(!root) return 0;
    if((!root->left && !root->right))
    {
        int temp = root->data;
        root->data = 0;
        return temp;
    }
    
    int l = util(root->left);
    int r = util(root->right);
    
    int prev = root->data;
    root->data = l+r;
    return prev+root->data;
}

void toSumTree(Node *node)
{
    if(!node || (!node->right && !node->left)) return;
    
    util(node);
}
//END

int main()
{
    struct Node *root = new Node(8);
    
    root->left = new Node(5);
    root->right = new Node(9);
    
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    root->right->right = new Node(2);
    root->right->left = new Node(10);
    \
    //virtualizing output tree
    cout<<"Tree before Transformation:\n"<<endl;
    cout<<"                         "<<root->data<<endl;
    cout<<"                      /    \\"<<endl;
    cout<<"                     "<<root->left->data<<"      "<<root->right->data<<endl;
    cout<<"                    / \\    / \\"<<endl;
    cout<<"                  "<<root->left->left->data<<"    "<<root->left->right->data<<"  "<<root->right->left->data<<"  "<<root->right->right->data;
    cout<<"\n";
    
    //Transforming tree to follow children sum property
    toSumTree1(root);
    
    //virtualizing output tree
    cout<<"Tree after Transformation:\n"<<endl;
    cout<<"                         "<<root->data<<endl;
    cout<<"                      /    \\"<<endl;
    cout<<"                     "<<root->left->data<<"      "<<root->right->data<<endl;
    cout<<"                    / \\    / \\"<<endl;
    cout<<"                  "<<root->left->left->data<<"    "<<root->left->right->data<<"  "<<root->right->left->data<<"  "<<root->right->right->data;
    cout<<"\n";
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
