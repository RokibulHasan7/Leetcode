class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 1, i = 0;
        while(i < j && j < n){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i], nums[j]);
                j++; i++;
            }
            else if(nums[i] == 0 && nums[j] == 0){
                j++;
            }
            else{
                i++; j++;
            }
        }
    }
};