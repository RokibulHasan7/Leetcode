class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size(), low = 0, mid;
        while(high > low){
            mid = (high + low) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        int n = upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        return n;
        
    }
};