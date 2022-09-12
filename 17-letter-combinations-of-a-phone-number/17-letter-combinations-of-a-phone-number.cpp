class Solution {
public:
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(string digits, string output, int idx, vector<string>& ans){
        if(idx >= digits.length()){
            ans.push_back(output);
            return;
        }
        
        string start = mp[digits[idx]-'0'];
        
        for(int i = 0; i < start.length(); i++){
            output += start[i];
            solve(digits, output, idx+1, ans);
            output.pop_back();
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output = "";
        
        solve(digits, output, 0, ans);
        
        return ans;
    }
};






