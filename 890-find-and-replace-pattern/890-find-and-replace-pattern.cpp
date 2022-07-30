class Solution {
public:
    vector<int> numeric_pattern(string s){
        vector<int> ans;

        if(s.size() == 0){
            return ans;
        }

        unordered_map<char,int> mp;
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) == mp.end()){
                mp[s[i]] = idx++;
                ans.push_back(mp[s[i]]);
            }
            else{
                ans.push_back(mp[s[i]]);
            }
        }

        return ans;
    }


    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = words.size();

        vector<int> pattern_num = numeric_pattern(pattern);

        vector<string> ans;
        for(int i = 0; i < n; i++){
            vector<int> word_num = numeric_pattern(words[i]);

            if(pattern_num == word_num){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};