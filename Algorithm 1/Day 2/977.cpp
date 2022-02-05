class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a = 0, b = nums.size() - 1;
        int n = nums.size();
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            int tmp1 = pow(nums[a], 2);
            int tmp2 = pow(nums[b], 2);
            
            if(tmp1 > tmp2){
                ans[n - 1 - i] = tmp1;
                a++;
            }
            else{
                ans[n - 1 - i] = tmp2;
                b--;
            }
        }
        
        return ans;
    }
};