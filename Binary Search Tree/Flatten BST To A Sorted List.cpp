#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder(TreeNode<int>* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inOrder(root->left, in);
    in.push_back(root->data);
    inOrder(root->right, in);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> inorderVal;
    // store inorder sorted values
    inOrder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;

    for(int i=1; i<n; i++){

        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    // last node
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
