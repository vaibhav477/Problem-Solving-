class Solution {
public:
    vector<int> word_frequency(string s){
        vector<int> frequency(26,0);
        for(int i = 0; i < s.size(); i++){
            frequency[s[i]-'a']++;
        }

        return frequency;
    }


    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> max_freq(26,0);

        for(int i = 0; i < words2.size(); i++){
            vector<int> freq = word_frequency(words2[i]);
            for(int j = 0; j < 26; j++){
                max_freq[j] = max(freq[j] , max_freq[j]);
            }
        }

        for(int i = 0; i < words1.size(); i++){
            vector<int> freq = word_frequency(words1[i]);
            int flag = 1;

            for(int j = 0; j < 26; j++){
                if(freq[j] < max_freq[j]){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};