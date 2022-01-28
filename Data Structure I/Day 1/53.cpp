class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return DivideAndConquer(nums, 0, nums.size()-1);
    }
    
    int DivideAndConquer(vector<int>& arr, int l, int r){
        if(l > r){
            return INT_MIN;
        }
        
        int mid = (l+r)/2, lSum = 0, rSum = 0;
        int currSum = 0;
        
        for(int i = mid-1; i >= l; i--){
            currSum += arr[i];
            lSum = max(lSum, currSum);
        }
        
        currSum = 0;
        for(int i = mid+1; i <= r; i++){
            currSum += arr[i];
            rSum = max(rSum, currSum);
        }
        
        return max(DivideAndConquer(arr, l, mid-1), max(DivideAndConquer(arr, mid+1, r), lSum+ arr[mid]+ rSum));
    }
};

///O(NlogN)