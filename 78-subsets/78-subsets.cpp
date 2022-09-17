class Solution {
public:
    
    void solve(vector<int>& nums, vector<int>& output, int idx, vector<vector<int>>& ans){
        if(idx >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        solve(nums, output, idx+1, ans);
        output.push_back(nums[idx]);
        solve(nums, output, idx+1, ans);
        output.pop_back();
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(nums, output, 0, ans);
        
        return ans;
    }
};