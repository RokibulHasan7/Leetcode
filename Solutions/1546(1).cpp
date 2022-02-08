class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0, last = -1;
        unordered_map<int, int> umap;
        umap[0] = -1;
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(umap.find(sum - target) != umap.end() && umap[sum - target] >= last){
                cnt++; last = i;
            }
            
            umap[sum] = i;
        }
        
        return cnt;
    }
};
