class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int idx, int n){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        return dp[idx] = max(nums[idx] + solve(nums, dp, idx + 2, n), solve(nums, dp, idx + 1, n));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, dp, 0, nums.size());
    }
    
};