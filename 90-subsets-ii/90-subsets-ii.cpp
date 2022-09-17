class Solution {
public:
    void solve(vector<int>& nums, vector<int>& output, int idx, set<vector<int>>& ans_helper, vector<vector<int>>& ans){
        if(idx >= nums.size()){
            //sort(output.begin(), output.end());
            if(ans_helper.find(output) == ans_helper.end()){
                ans.push_back(output);
            }
            ans_helper.insert(output);
            return;
        }
        
        solve(nums, output, idx+1, ans_helper, ans);
        output.push_back(nums[idx]);
        solve(nums, output, idx+1, ans_helper, ans);
        output.pop_back();
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> ans_helper;
        vector<int> output;
        
        solve(nums, output, 0, ans_helper, ans);
        
        return ans;
    }
};