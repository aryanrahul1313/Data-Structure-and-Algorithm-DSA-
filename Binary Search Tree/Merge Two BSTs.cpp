#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>* &head){
    if(root == NULL){
        return;
    }

    convertIntoSortedDLL(root->right, head);    
    root->right = head;

    if(head != NULL){
        head->left = root;
    }
    head = root;

    convertIntoSortedDLL(root->left, head);
}

TreeNode<int>* mergeLinkedList(TreeNode<int> *&head1, TreeNode<int> *&head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                head1 = head1->right;
                tail = head;
            }
            else{
                tail->right = head1;
                head1->left = tail;
                tail = tail->right;
                head1 = head1->right;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                head2 = head2->right;
                tail = head;
            }
            else{
                tail->right = head2;
                head2->left = tail;
                tail = tail->right;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = tail->right;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = tail->right;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode<int> *head){
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head, int n){
    // base case
    if(n <= 0 || head == NULL){
        return NULL;
    }

    TreeNode<int> *left = sortedLLToBST(head, n/2);
    
    TreeNode<int> *root = head;
    root->left = left;
    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
   
    //step1 : convert BST into sorted DLL in-place
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    //step2 : merge sorted linked list
    TreeNode<int> *head = mergeLinkedList(head1, head2);

    //step3 : convert sortee LL into BST
    int n = countNodes(head);
    return sortedLLToBST(head, n);
}
