class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int LIS[n + 1];
        LIS[0] = 1;
        
        for(int i = 1; i < n; i++){
            LIS[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }
        
        return *max_element(LIS, LIS + n);
    }
};
