class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[target + 5];
        fill(dp, dp + target + 5, 0);
        
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++){
            dp[i] = 0;
            for(auto x : nums){
                if(i >= x){
                    dp[i] += dp[i - x];
                }
            }
        }
        return dp[target];
    }
};
