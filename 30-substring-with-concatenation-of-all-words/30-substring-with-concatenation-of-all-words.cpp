class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), k = words[0].size(), l = words.size();
        map<string, int> mp;
        for(int i = 0; i < l; i++){
            mp[words[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < (n+1-(l*k)); i++){
            map<string, int> help;
            for(int j = i; j < i+(l*k); j += k){
                string temp = s.substr(j , k);
                if(mp.find(temp) != mp.end()){
                    help[temp]++;
                }
                else{
                    break;
                }
                
                if(help == mp){
                    ans.push_back(i);
                }
            }
        }
        
        return ans;
    }
};