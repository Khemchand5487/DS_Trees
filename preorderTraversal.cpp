//preorder traversal of a binary tree in c++

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

//iterative approach for preorder traversal
void preorder_itr(Node* root)
{
    vector<int> res;
    if(root == NULL) return;
    
    stack<Node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        root = st.top();
        st.pop();
        res.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }

    for(int i: res)
    {
        cout<<i<<" ";
    }
    cout<<"\n";
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
    preorder_itr(root);
    
    //preorder traversal using recursion
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
