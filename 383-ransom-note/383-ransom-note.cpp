class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> mp;
        for(int i = 0; i < magazine.size(); i++){
            mp[magazine[i]]++;
        }
        
        int flag = 1;
        for(int i = 0; i < ransomNote.size(); i++){
            if(mp[ransomNote[i]] > 0){
                mp[ransomNote[i]]--;
            }
            else{
                flag = 0;
                break;
            }
        }
        
        if(flag){
            return true;
        }
        else{
            return false;
        }
    }
};