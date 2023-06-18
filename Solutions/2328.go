import "fmt"
var MOD = 1000000007
func checker(i, j, prev, n, m int, grid[][]int, dp[][]int) int{
    if i < 0 || j < 0 || i >= n || j >= m || grid[i][j] <= prev {
        return 0
    }
    if dp[i][j] != -1 {
        return dp[i][j]
    }

    top := checker(i - 1, j, grid[i][j], n, m, grid, dp)
    bottom := checker(i + 1, j, grid[i][j], n, m, grid, dp)
    left := checker(i, j - 1, grid[i][j], n, m, grid, dp)
    right := checker(i, j + 1, grid[i][j], n, m, grid, dp)

    dp[i][j] = (top + bottom + left + right + 1) % MOD
    return dp[i][j]
}
func countPaths(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])
    if n == 1 && m == 1 {
        return 1
    }
    
    dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, m)
        for j := range dp[i] {
			dp[i][j] = -1
		}
	}
   
    ans := 0
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if dp[i][j] == -1{
                ans = (ans + checker(i, j, -1, n, m, grid, dp)) % MOD
            } else {
                ans = (ans + dp[i][j]) % MOD
            }
        }
    }
    return ans
}
