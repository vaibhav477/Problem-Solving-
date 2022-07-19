class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(rowIndex >= 1){
            ans.push_back({1,1});
        }
        
        for(int i = 2; i <= rowIndex; i++){
            vector<int> temp(i+1);
            temp[0] = 1, temp[i] = 1;
            for(int j = 1; j < i; j++){
                temp[j] = ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        
        return ans[rowIndex];
    }
};