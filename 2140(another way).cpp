class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long dp[100005] = {0};
        for(int i = questions.size() - 1; i >= 0; i--){
            int next = i + questions[i][1] + 1;
            if(next < questions.size()){
                dp[i] = max(dp[i + 1], (long long)questions[i][0] + dp[next]);
            }
            else{
                dp[i] = max(dp[i + 1], (long long)questions[i][0]);
            }
        }
        return dp[0];
    }
};
