class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 5];
        fill(dp, dp + amount + 5, amount + 1);
        
        dp[0] = 0;
        for(auto x: coins){
            for(int i = x; i <= amount; i++){
                dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
