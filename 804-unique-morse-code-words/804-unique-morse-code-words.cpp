class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> ans;
        for(auto word : words){
            string output = "";
            for(auto ch : word){
                output += morse[ch-'a'];
            }
            ans.insert(output);
        }
        
        return ans.size();
    }
};