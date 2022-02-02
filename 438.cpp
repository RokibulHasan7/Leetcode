class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> ans;
        vector<int> count_p(26, 0);
        vector<int> count_s(26, 0);
        
        if(n < m){
            return ans;
        }
        
        for(int i = 0; i < m; i++){
            count_p[p[i] - 'a']++;
            count_s[s[i] - 'a']++;
        }
        
        if(count_s == count_p){
            ans.push_back(0);
        }
        
        for(int i = m; i < n; i++){
            count_s[s[i - m] - 'a']--;
            count_s[s[i] - 'a']++;
            
            if(count_p == count_s){
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};
