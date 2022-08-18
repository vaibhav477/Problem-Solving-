class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        
        priority_queue<int> pq;
        for(auto i : mp){
            pq.push(i.second);
        }
        
        int count = 0, ans = 0;
        while(!pq.empty()){
            if(ans >= (n/2)){
                break;
            }
            ans += pq.top();
            count++;
            pq.pop();
        }
        
        return count;
    }
};