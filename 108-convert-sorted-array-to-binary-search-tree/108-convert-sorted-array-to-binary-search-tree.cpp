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
    
    TreeNode* sortedArrayToBST_help(vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST_help(nums, start, mid-1);
        root->right = sortedArrayToBST_help(nums, mid+1, end);
        
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        return sortedArrayToBST_help(nums, start, end);
    }
};
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    