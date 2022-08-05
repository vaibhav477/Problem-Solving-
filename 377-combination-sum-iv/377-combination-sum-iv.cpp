class Solution {
public:
    
    int combinationSum4_help(vector<int>& nums, int target, vector<long long>& dp){
        
        // base case
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        
        // return if already present
        if(dp[target] != -1){
            return dp[target];
        }
        
        // small calculation and recursive call
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += combinationSum4_help(nums, target-nums[i], dp);
        }
        dp[target] = ans;
        
        return dp[target];
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1, -1);
        
        return combinationSum4_help(nums, target, dp);
    }
};