class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* suc = NULL;
        while(root)
        {
            if(x->data>=root->data) root = root->right;
            else
            {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};
