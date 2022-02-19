class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string, int> mp;
        for(int i = 0; i < wordDict.size(); i++){
            mp[wordDict[i]] = 1;
        }
        
        bool dp[n + 1];
        fill(dp, dp + n + 1, false);
        dp[0] = true;
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] == true && mp[s.substr(j, i - j)] == 1){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
