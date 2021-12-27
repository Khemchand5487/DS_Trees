//inorder traversal of a binary tree in c++

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

//inorder(Left Root Right) traversal of binary tree 
void inorder(Node *root)
{
    if(root==NULL) return;
    
    inorder(root->left); //traversing left subtree
    cout<<root->data<<" "; //printing root node
    inorder(root->right); //traversing right subtree
}

void inorder_itr(Node* root)
{
    vector<int> res;
    if(root==NULL) return;
    
    stack<Node*> st;
    Node* node = root;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            res.push_back(node->data);
            node = node->right;
        }
    }
    
    for(int i: res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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
    
    //iterative approach
    inorder_itr(root);
    
    //recursive approach
    inorder(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/