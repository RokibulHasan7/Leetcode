class Solution {
public:
    long long dp[100007];
    long long solve(vector<vector<int>>& questions, int idx){
        if(idx >= questions.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        long long op1 = INT_MIN, op2 = INT_MIN;
        
        op1 = questions[idx][0] + solve(questions, idx + 1 + questions[idx][1]);
        op2 = solve(questions, idx + 1);
        
        return dp[idx] = max(op1,op2);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return solve(questions, 0);
    }
};
