/***************************************************************************
Title: Minimum time taken to burn the binary tree from a given node in c++
Problem link: https://bit.ly/3z3YEJY
Problem Name: Time To Burn Tree
****************************************************************************/


/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>

BinaryTreeNode<int>* bfs(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& parents, int start)
{
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* startNode;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* temp = q.front();
        if(temp->data == start) startNode = temp;
        q.pop();
        if(temp->left)
        {
            parents[temp->left] = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            parents[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return startNode;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
 	if(!root) return 0;
 
    unordered_map<BinaryTreeNode<int>*, int> isVisited;
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parents;
    BinaryTreeNode<int>* target = bfs(root, parents, start);

    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    isVisited[target] = 1;
    int k = 0, flag;
    while(!q.empty())
    {
        flag=0;
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            BinaryTreeNode<int>* temp = q.front();
            q.pop();
            if(temp->left && !isVisited[temp->left])
            {
                isVisited[temp->left] = 1;
                q.push(temp->left);
                flag=1;
            }
            if(temp->right && !isVisited[temp->right])
            {
                isVisited[temp->right] = 1;
                q.push(temp->right);
                flag=1;
            }
            if(parents.find(temp) != parents.end() && !isVisited[parents[temp]])
            {
                isVisited[parents[temp]] = 1;
                q.push(parents[temp]);
                flag=1;
            }
        }
        if(flag) k++;
    }

    return k;
}
