// Print root to node path in binary tree in c++;

// Problem link: https://www.interviewbit.com/problems/path-to-given-node/

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

bool getpath(Node* root, vector<int>& res, int x)
{
    if(!root) return false;
    res.push_back(root->data);
    if(root->data ==x) return true;

    if((getpath(root->left, res, x))||getpath(root->right, res, x)) return true;

    res.pop_back();
    return false;
}

// find path from root node to given node
void solve(Node* A, int B) {
    vector<int> res;
    if(!A) return;
    getpath(A, res, B);
    
    for(int i: res)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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
    
    //print path from root to given node;
    solve(root, 10);
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
