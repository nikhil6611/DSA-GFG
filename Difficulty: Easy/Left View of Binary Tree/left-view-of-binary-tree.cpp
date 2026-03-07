/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void helper(Node* root, int level, int &maxlevel,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(maxlevel<level){
            ans.push_back(root->data);
            maxlevel = level;
        }
        helper(root->left, level+1,maxlevel,ans);
        helper(root->right,level+1,maxlevel,ans);
    }
    vector<int> leftView(Node *root) {
        int maxlevel=0;
        vector<int>ans;
        helper(root,1,maxlevel,ans);
        return ans;
        
    }
};