class Solution {
public:
    
    bool isSubsequence(string s, string word, int n, int m){
        int j = 0;
        for(int i = 0; i < n && j < m; i++){
            if(s[i] == word[j]){
                j++;
            }
        }
        
        return j == m;
    }
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, bool> mp;
        
        for(auto word : words){
            if(mp.find(word) != mp.end()){
                if(mp[word] == true){
                    count++;
                }
                continue;
            }
            
            mp[word] = isSubsequence(s,word,s.length(),word.length());
            if(mp[word] == true){
                count++;
            }
        }
        
        return count;
    }
};