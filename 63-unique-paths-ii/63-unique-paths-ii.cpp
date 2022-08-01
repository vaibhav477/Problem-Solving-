class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n));
        
        for(int i = 0; i < m; ){
            if(obstacleGrid[i][0] == 1){
                while(i < m){
                    dp[i++][0] = 0;
                }
            }
            else{
                dp[i++][0] = 1;
            }
        }
        for(int i = 0; i < n; ){
            if(obstacleGrid[0][i] == 1){
                while(i < n){
                    dp[0][i++] = 0;
                }
            }
            else{
                dp[0][i++] = 1;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};