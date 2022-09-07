class Solution {
public:
    // binary search approach
    
    int helper(vector<long long>& pre, int idx, long long value, int k){
        int i = 0, j = idx, m, ans = -1;
        while(i <= j){                    // we have to include i=j case also
            long long sum = pre[idx];
            m = (i+j)/2;
            if(m!=0){
                sum -= pre[m-1];
            }
            
            if((idx-m+1)*(value)*1LL - sum <= k){
                ans = m;
                j = m-1;
            }
            else{
                i = m+1;
            }
        }
        return ans;
    }
    
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int,int> mp;
        for(int i = 0; i < n ;i++){
            mp[nums[i]]++;
        }
        
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1]+nums[i];
        }
        
        int maxi = 0;
        for(int i = 0; i < n; i++){
            if(mp[nums[i]] == 0){
                continue;
            }
            
            int j = helper(pre, i-1, nums[i], k);
            if(j != -1){
                maxi = max(maxi, i-j+mp[nums[i]]);
            }
            else{
                maxi = max(maxi, mp[nums[i]]);
            }
            
            mp[nums[i]] = 0;
        }
        
        return maxi;
    }
};