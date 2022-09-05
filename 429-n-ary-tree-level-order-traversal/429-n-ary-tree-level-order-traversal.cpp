/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> help;
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                Node* t = q.front();
                q.pop();
                
                help.push_back(t->val);
                
                for(auto n : t->children){
                    q.push(n);
                }
            }
            ans.push_back(help);
        }
        
        return ans;
    }
};