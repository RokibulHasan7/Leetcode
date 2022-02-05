class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        for(int i = 0; i < k / 2; i++){
            swap(nums[i], nums[k - 1 - i]);
        }
        int i = k, pos = (n - k) / 2;
        int tmp = 0;
        while(tmp < pos){
            swap(nums[i], nums[n - 1 - tmp]);
            tmp++; i++;
        }
    }
};