class Solution {
public:
    int solve(vector<int>& nums, vector<vector<int>> & dp, int idx, int n, bool pick){
        if(idx >= n){
            return 0;
        }
        if(idx == n - 1){
            if(pick){
                return 0;
            }
            return nums[idx];
        }
        
        if(dp[idx][pick] != -1){
            return dp[idx][pick];
        }
        
        return dp[idx][pick] = max(nums[idx] + solve(nums, dp, idx + 2, n, pick),
                                   solve(nums, dp, idx + 1, n, pick));
    }
    
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        
        return max((nums[0] + solve(nums, dp, 2, nums.size(), true)),
                   solve(nums, dp, 1, nums.size(), false));
    }
};
