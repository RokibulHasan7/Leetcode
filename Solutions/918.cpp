class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> suffix(n);

        suffix[n - 1] = nums[n - 1];
        int suffix_sum = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix_sum += nums[i];
            suffix[i] = max(suffix[i + 1], suffix_sum);
        }

        int normalSum = nums[0];
        int special_sum = nums[0];
        int currSum = 0;
        int prefixSum = 0;

        for (int i = 0; i < n; ++i) {
            // Kadane algo start
            currSum += nums[i];
            normalSum = max(normalSum, currSum);
            if(currSum < 0){
                currSum = 0;
            }
            // kadane algo end
            prefixSum += nums[i];
            if (i + 1 < n) {
                special_sum = max(special_sum, prefixSum + suffix[i + 1]);
            }
        }
        return max(normalSum, special_sum);
    }
};
