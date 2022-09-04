class Solution {
public:
    
    void solve(int len, int k, int curr_num, int curr_digit, vector<int>& ans){
        if(len == 0){
            ans.push_back(curr_num);
            return;
        }
        
        for(int i = 0; i < 10; i++){
            if(abs(i-curr_digit) == k){
                solve(len-1, k, curr_num*10 + i, i, ans);
            }
        }
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(int i = 1; i < 10; i++){
            solve(n-1, k, i, i, ans);
        }
        
        return ans;
    }
};