/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int goodNodes_helper(TreeNode* root, int maxi){
        if(root == NULL){
            return 0;
        }
        
        int ans = goodNodes_helper(root->left , max(maxi, root->val)) + goodNodes_helper(root->right , max(maxi, root->val));
        
        if(root->val >= maxi){
            ans++;
        }
        
        return ans;
    }
    
    
    int goodNodes(TreeNode* root) {
        return goodNodes_helper(root, INT_MIN);
    }
};