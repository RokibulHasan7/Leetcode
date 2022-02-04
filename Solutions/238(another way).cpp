class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int before[nums.size() + 1];
        int after[nums.size() + 1];
        int n = nums.size();
        
        fill(before, before + n + 1, 1);
        fill(after, after + n + 1, 1);
        
        for(int i = 1; i < n; i++){
            before[i] = before[i - 1] * nums[i - 1];
        }
        
        for(int i = n - 2; i >= 0; i--){
            after[i] = after[i + 1] * nums[i + 1];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(before[i] * after[i]);
        }
        return ans;
    }
};
