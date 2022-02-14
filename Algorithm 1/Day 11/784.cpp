class Solution {
public:
    void solve(string &s, vector<string>& ans, int idx){
        ans.push_back(s);
        if(idx == s.size()){
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = s[i] + 32;
                solve(s, ans, i + 1);
                s[i] = s[i] - 32;
            }
            else if(s[i] >= 97 && s[i] <= 122){
                s[i] = s[i] - 32;
                solve(s, ans, i + 1);
                s[i] = s[i] + 32;
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, ans, 0);
        return ans;
    }
};