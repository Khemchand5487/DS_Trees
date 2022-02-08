//Program to convert Binary Tree to Doubly Linked List using Inorder traversal

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
void bt_dll(Node *root, Node* &head, Node* &prev)
{
    if(root==NULL) return;
    bt_dll(root->left, head, prev);
    
    if(head==NULL)
    {
        root->left=prev;
        head = root;
        prev = head;
    }
    else
    {
        root->left = prev;
        prev->right = root;
        prev = root;
    }
    bt_dll(root->right, head, prev);
    
}

Node* bt_dll_itr(Node *root)
{
    if(root==NULL) return NULL;
    
    Node * prev = NULL, *head=NULL;
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
            if(head==NULL)
            {
                head=node;
                head->left=NULL;
                prev = head;
            }
            else
            {
                node->left=prev;
                prev->right = node;
                prev = node;
            }
            node = node->right;
        }
    }
    prev->right = NULL;
    return head;
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
    
    // Node* head = bt_dll_itr(root);
    
    // while(head!=NULL)
    // {
    //     cout<<(head->data)<<" ";
    //     head = head->right;
    // }
    // cout<<endl;
    
    Node* head = NULL, *prev = NULL;
    bt_dll(root, head, prev);
    
    while(head!=NULL)
    {
        cout<<(head->data)<<" ";
        head = head->right;
    }
    return 0;
}
