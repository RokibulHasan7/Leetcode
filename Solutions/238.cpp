class Solution {
public:
    int solve(vector<int>& nums, vector<int>& ans, int pro, int i){
        if(i >= nums.size()){
            return 1;
        }
        int pro2 = solve(nums, ans, pro * nums[i], i + 1);
        ans[i] = pro * pro2;
        return pro2 * nums[i];
    }
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        solve(nums, ans, 1, 0);
        return ans;
    }
};
