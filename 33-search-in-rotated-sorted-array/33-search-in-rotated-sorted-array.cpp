class Solution {
public:
    int search(vector<int>& arr, int k) {
        int i = 0, j = size(arr) - 1, m;
        while(i<=j){
            m = (i + j) >> 1;
            if(arr[m]==k){
                return m;
            }
            //if right array is sorted
            if(arr[m]<=arr[j]){
                //if key is part of right array
                if(arr[m]<k and k<=arr[j]){
                    i = m + 1;
                }
                else{
                    j = m - 1;
                }
            }
            else{
                //if key is in part of left array
                if(arr[i]<=k and k<=arr[m]){
                    j = m -1;
                }
                else{
                    i = m + 1;
                }
            }
        }
        return -1;
    }
};