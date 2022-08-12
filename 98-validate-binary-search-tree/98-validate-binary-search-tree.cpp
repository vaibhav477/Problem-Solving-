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
    
    bool isValidBST_helper(TreeNode* root, long long low, long long end){
        // base case
        if(root == NULL){
            return true;
        }
        
        if((root->val < end) && (root->val > low)){
            return (isValidBST_helper(root->left, low, root->val) && (isValidBST_helper(root->right, root->val, end)));
        }
        else{
            return false;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, LONG_MIN, LONG_MAX);
    }
};