class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        
        dp[0] = 1;
        for(int i = 1; i < n; i++){
            dp[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if(nums[j] >= nums[i]){
                    continue;
                }
                
                int possible_ans = dp[j]+1;
                dp[i] = max(dp[i] , possible_ans);
            }
        }
        
        int best_ans = 1;
        for(int i = 0; i < n; i++){
            best_ans = max(best_ans , dp[i]);
        }
        
        return best_ans;
    }
};