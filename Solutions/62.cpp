class Solution {
public:
    int dir[2][2] = {{0, 1}, {1, 0}};
    int dfs(vector<vector<int>>& dp, int m, int n, int i, int j){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        int ans = 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        for(int p = 0; p < 2; p++){
            int x = i + dir[p][0];
            int y = j + dir[p][1];
            ans += dfs(dp, m, n, x, y);
        }
        
        dp[i][j] = ans;
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return dfs(dp, m, n, 0, 0);
    }
};
