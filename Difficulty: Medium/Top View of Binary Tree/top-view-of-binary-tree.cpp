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
    
    vector<int> topView(Node *root) {
        vector<int>ans;
        map<int,Node*>m;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int hd=curr.second;
            if(m.find(hd)==m.end()){
                m[hd]=curr.first;
            }
            if(curr.first->left){
                q.push(make_pair(curr.first->left,hd-1));
            }
            if(curr.first->right){
                q.push(make_pair(curr.first->right,hd+1));
            }
        }
        for(auto it:m){
            ans.push_back(it.second->data);
        }
        return ans;
        
    }
};