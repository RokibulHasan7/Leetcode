func uniquePathsWithObstacles(obstacleGrid [][]int) int {
    m, n := len(obstacleGrid), len(obstacleGrid[0])
    dp := make([][]int, m)  
    
    for i := 0; i < m; i++ {
        dp[i] = make([]int, n)  // Initialize the inner slices
        for j := 0; j < n; j++ {
            if obstacleGrid[i][j] == 1 {
                dp[i][j] = 0
            } else if i == 0 && j == 0 {
                dp[i][j] = 1
            } else if i == 0 {
                dp[i][j] = dp[i][j-1]
            } else if j == 0 {
                dp[i][j] = dp[i-1][j]
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
    }

    return dp[m-1][n-1]
}
