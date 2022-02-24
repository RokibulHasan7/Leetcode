class Solution {
public:
    int countSubstrings(string s) {
        int Ans = 0;
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--; r++; Ans++;
            }
            
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--; r++; Ans++;
            }
        }
        
        return Ans;
    }
};
