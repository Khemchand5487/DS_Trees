//postorder traversal of a binary tree in c++

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

//postorder(Left Right Root) traversal of binary tree 
void postorder(Node *root)
{
    if(root==NULL) return;
    
    postorder(root->left); //traversing left subtree
    postorder(root->right); //traversing right subtree
    cout<<root->data<<" "; //printing root node
}

/*
    Time Complexity of below approch: O(N)
    Time Complexity of below approch: O(2N)
*/

//iterativ approach using 2 stacks
void postorder_itr1(Node* root)
{
    if(root==NULL) return;
        
    stack<Node*> st1;
    stack<int> st2;
    st1.push(root);
    
    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root->data);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }
    while(!st2.empty())
    {
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<endl;
}

/*
    Time Complexity of below approch: O(2N)
    Time Complexity of below approch: O(N)
*/

//iterativ approach using 1 stacks
void postorder_itr2(Node* root)
{
    vector<int> res;
    if(root==NULL) return;
    
    stack<Node*> st;
    Node* curr = root, *temp;
    while(curr || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if(temp==NULL)
            {
                temp = st.top();
                st.pop();
                res.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    res.push_back(temp->data);
                }
            }
            else
            {
                curr=temp;
            }
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
    
    //iterativ approach using 2 stacks
    postorder_itr1(root);
    
    //iterativ approach using 1 stacks
    postorder_itr2(root);
    
    //recursive approach
    postorder(root);
}

/*
The above code represent a binary tree like below:
                         8
                      /    \
                     5      9
                    / \    / \
                  1    3  10  2
*/