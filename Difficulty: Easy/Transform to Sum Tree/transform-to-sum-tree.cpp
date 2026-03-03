/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    int helper(Node* node){
        if(node->left==NULL && node->right==NULL){
            int val = node->data;
            node->data=0;
            return val;
        }
        int left=0,right=0;
        if(node->left){
            left = helper(node->left);
        }
        if(node->right){
             right = helper(node->right);
        }
        int val = node->data;
        node->data = left+right;
        return node->data+val;
    }
    void toSumTree(Node *node) {
        int ans = helper( node);
        
        
    }
};