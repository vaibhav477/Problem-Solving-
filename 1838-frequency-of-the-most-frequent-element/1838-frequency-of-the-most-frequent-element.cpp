class Solution {
public:
    // sliding window technique
    
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0, j = 0, maxi = 0;
        long long sum = 0;
        while(i < n){
            sum += nums[i];  // also considering the element in which we have to convert previous elements                                   into.
            
            while(j < i && (nums[i]*1LL*(i-j+1) - sum) > k){    // decreasing the window size if total
                sum -= nums[j++];                              // steps is exceeding k.
            }                                                 // 1LL is used to convert any value to long                                                                    long.
            
            maxi = max(maxi, (i-j+1));   // storing the maximum length
            i++; // moving window forward
        }
        return maxi;
    }
};