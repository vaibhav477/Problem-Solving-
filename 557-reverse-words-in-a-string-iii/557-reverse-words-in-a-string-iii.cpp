class Solution {
public:
    
    void reverse(string& s, int l, int r){
        int n = r-l;
        
        for(int i = 0; i < n/2; i++){
            swap(s[i+l], s[n-i-1+l]);
        }
    }
    
    
    string reverseWords(string s) {
        int n = s.length();
        
        int i = 0, j = 0;
        while(j <= n){
            if(s[j]==' ' || j==n){
                reverse(s, i, j);
                j++;
                i = j;
            }
            else{
                j++;
            }
        }
        return s;
    }
};