class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++){
            mp[s[i]] = -1;
        }
        
        int i = 0, start = -1;
        while(i < n){
            if(mp[s[i]] >= start){
                start = mp[s[i]];
            }
            mp[s[i]] = i;
            ans = max(ans, i - start);
            i++;
        }
        
        return ans;
    }
};