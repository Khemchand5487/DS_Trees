//Preorder, inorder and postorder traversal only in one traversal in c++

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

/*
    Time Complexity of below approch: O(3N)
    Time Complexity of below approch: O(4N)
*/

//preorder, inorder and postorder traversal only in one traversal;
void preInPostTraversal(Node* root)
{
    if(root==NULL) return;
    
    vector<int> pre, in, post;
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    
    while(!st.empty())
    {
        auto it = st.top();
        st.pop();
        if(it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->left) st.push({it.first->left, 1});
        }
        else if(it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            
            if(it.first->right) st.push({it.first->right, 1});
        }
        else post.push_back(it.first->data);
    }
    
    //printing result
    cout<<"Preorder Traversal: ";
    for(int i: pre)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"Inorder Traversal: ";
    for(int i: in)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    cout<<"Postorder Traversal: ";
    for(int i: post)
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
    
    preInPostTraversal(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/