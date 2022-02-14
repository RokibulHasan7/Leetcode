class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int idx, int n){
        if(idx == n - 1){
            ans.push_back(nums);
            return;
        }
        
        for(int i = idx; i < n; i++){
            swap(nums[idx], nums[i]);
            solve(nums, ans, idx + 1, n);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = nums.size();
        int idx = 0;
        solve(nums, ans, idx, n);
        
        return ans;
    }
};