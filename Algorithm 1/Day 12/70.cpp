class Solution {
public:
    int dp[46];
    int fact(int x){
        if(x == 0){
            return 1;
        }
        if(x == 1){
            return 1;
        }
        if(dp[x] != -1){
            return dp[x];
        }
        
        return dp[x] = fact(x - 1) + fact(x - 2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return fact(n);   
    }
};