class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> prefixMod(k, 0);
        // Incase the prefixSums being themselves divisible by k 
        // and the case of the whole array being a subarray whose sum is divisible by k
        prefixMod[0] = 1;
        int Ans = 0;
        int prefixSum = 0;
        for(auto num: nums){
            // (a % b + b) % b for neg number
            prefixSum = (prefixSum + num % k + k) % k;
            Ans += prefixMod[prefixSum];
            prefixMod[prefixSum]++;
        }

        return Ans;
    }
};
