class Solution {
public:
    const int mod = (int)1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++){
            arr[i].first = efficiency[i];
            arr[i].second = speed[i];
        }
        
        sort(arr.rbegin(), arr.rend());
        long long sum = 0, maxi = 0, min_eff = INT_MAX;
        for(int i = 0; i < k; i++){
            sum += arr[i].second;
            min_eff = arr[i].first;
            maxi = max(maxi, sum*min_eff);
            pq.push(arr[i].second);
        }
        
        for(int i = k; i < n; i++){
            sum -= pq.top();
            pq.pop();
            sum += arr[i].second;
            min_eff = arr[i].first;
            maxi = max(maxi, sum*min_eff);
            pq.push(arr[i].second);
        }
        
        return maxi%mod;
    }
};