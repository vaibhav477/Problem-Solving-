class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        sort(changed.begin(), changed.end());
        
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[changed[i]]++;
        }
        
        int i;
        vector<int> ans;
        for(i = 0; i < n; i++){
            if(mp[changed[i]] > 0){
                mp[changed[i]]--;
                if(mp[2*changed[i]] > 0){
                    ans.push_back(changed[i]);
                    mp[2*changed[i]]--;
                }
                else{
                    break;
                }
            }
        }
        
        if((i != n) || (n%2 != 0)){
            ans.clear();
        }
        
        return ans;
    }
};