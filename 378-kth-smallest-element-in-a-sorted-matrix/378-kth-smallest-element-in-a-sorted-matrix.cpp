class Solution {
public:
    
    int rank_cal(vector<vector<int>>& matrix, int& mid){
        int n = matrix.size();
        int count = 0, i = n-1, j = 0;
        
        while(i >= 0 && j < n){
            if(matrix[i][j] > mid){
                i--;
            }
            else{
                count += (i+1);
                j++;
            }
        }
        
        return count;
    }
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int start = matrix[0][0], end = matrix[n-1][n-1];
        
        while(start <= end){
            int mid = start + (end-start)/2;
            int rank = rank_cal(matrix, mid);
            
            if(rank < k){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return start;
    }
};

