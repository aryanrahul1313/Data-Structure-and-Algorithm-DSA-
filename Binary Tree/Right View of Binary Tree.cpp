/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root, vector<int> &ans, int level){
        // base case
        if(root == NULL){
            return;
         }
    
         // we entered into new level
        if(level == ans.size()){
            ans.push_back(root->data);
        }
    
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       solve(root, ans, 0);
       return ans;
    }
};