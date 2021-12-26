// Representation of a binary tree in c++;

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

int main()
{
    struct Node *root = new Node(8);
    
    root->left = new Node(5);
    root->right = new Node(9);
    
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    root->right->right = new Node(2);
    root->right->left = new Node(10);
    
    //virtualizing output tree
    cout<<"The given code represent a binary tree like below:\n"<<endl;
    cout<<"                         8"<<endl;
    cout<<"                      /    \\"<<endl;
    cout<<"                     5      9"<<endl;
    cout<<"                    / \\    / \\"<<endl;
    cout<<"                  1    3  10  2";
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
