class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_set<char> st;
        
        int l = 0, r = 0;
        while(r < n){
            if(st.find(s[r]) == st.end()){
                st.insert(s[r]);
                ans = max(ans, r - l + 1);
                r++;
            }
            else{
                while(s[l] != s[r]){
                    st.erase(s[l]);
                    l++;
                }
                st.erase(s[l]);
                l++;
            }
        }
        
        return ans;
    }
};