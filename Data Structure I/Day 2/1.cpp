class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int>ans;
        vector<pair<int,int>> vec;
        for(int i=0;i<sz;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(), vec.end());
        int i = 0, j = sz-1;
        while(i<j){
            if(vec[i].first + vec[j].first > target){
                j--;
            }
            else if(vec[i].first + vec[j].first < target){
                i++;
            }
            else{
                ans.push_back(vec[i].second);
                ans.push_back(vec[j].second);
                break;
            }
        }
        return ans;
    }
};