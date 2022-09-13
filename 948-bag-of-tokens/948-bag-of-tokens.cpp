class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1;
        int score = 0, max_score = 0;
        while(i <= j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i++];
            }
            else if(power < tokens[i] && score > 0){
                score--;
                power += tokens[j--];
            }
            else{
                break;
            }
            max_score = max(max_score, score);
        }
        
        return max_score;
    }
};