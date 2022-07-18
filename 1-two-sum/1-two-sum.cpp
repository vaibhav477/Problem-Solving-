class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , int> mp;
        int curr_idx = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int req_num = target - nums[curr_idx];
            if(mp.find(req_num) != mp.end()){
                ans.push_back(mp[req_num]);
                ans.push_back(curr_idx);
                break;
            }
            mp[nums[curr_idx]] = curr_idx;
            curr_idx++; 
        }

        return ans;
    }
};