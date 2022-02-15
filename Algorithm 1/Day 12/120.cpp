class Solution {
public:
    int solve(vector<vector<int>>& triangle, vector<vector<int>>& dp, int n, int idx){
        if(n == triangle.size() - 1){
            return triangle[n][idx];
        }
        
        if(dp[n][idx] != -1){
            return dp[n][idx];
        }
        
        int x = solve(triangle, dp, n + 1, idx);
        int y = solve(triangle, dp, n + 1, idx + 1);
        
        return dp[n][idx] = triangle[n][idx] + min(x, y);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 1){
            return triangle[0][0];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(triangle, dp, 0, 0);
    }
};