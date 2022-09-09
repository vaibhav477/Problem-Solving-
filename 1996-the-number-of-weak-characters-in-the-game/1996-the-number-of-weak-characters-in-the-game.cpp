class Solution {
public:
    
    static bool compare(vector<int>& v1, vector<int>& v2){
        if(v1[0] == v2[0]){
            return v1[1] >= v2[1];
        }
        return v1[0] < v2[0];
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), compare);
        
        int n = properties.size();
        int count = 0, max_def = properties[n-1][1];
        for(int i = n-2; i >= 0; i--){
            if(properties[i][1] < max_def){
                count++;
            }
            else{
                max_def = properties[i][1];
            }
        }
        
        return count;
    }
};