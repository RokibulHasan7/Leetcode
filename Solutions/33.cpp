class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid;
        
        while(l <= r){
            mid = (r + l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            // the left side is sorted
            if(nums[mid] >= nums[l]){
                 // figure out if element lies on the left half or not
                if(nums[mid] >= target && nums[l] <= target){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{     // rigt half is sorted
                // figure out if element lies on the right half or not
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        
        return - 1;
    }
};
